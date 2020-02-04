using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
using System.Diagnostics;

namespace JAProject_PolybiusSquare
{
    public partial class mainWindow : Form
    {
        byte[][] square;                                                //deklaracja dwuwymiarowej tablicy zmiennych typu byte

        public mainWindow()                                             //konstruktor obiektu klasy mainWindow 
        {
            square = new byte[5][];                                     //alokacja pamięci dla tablicy o pięciu wierszach i jedenastu kolumnach
            for(int i = 0; i < 5; i++)
            {
                square[i] = new byte[11];
            }
            InitializeComponent();

            threadNumericUpDown.Value = Environment.ProcessorCount;     //wpisanie w pole wyboru liczby wątków liczby procesorów w komputerze
        }

        //funkcja wywołująca funkcję encrypt dla fragmentu podanego tekstu do zaszyfrowania
        private void threadEncrypt(Distributor d, IntPtr polybiusArray) //parametrami funkcji są obiekt klasy Distributor i wskaźnik na tablicę Polibiusza
        {
            int index = d.getCounter();
            d.setResult(encrypt(d.getString(index), polybiusArray), index);
        }

        //funkcja szyfrująca tekst do zaszyfrowania
        private String encrypt(String text, IntPtr polybiusArray)
        {
            String encrypted = null;
            byte[] textArray = Encoding.ASCII.GetBytes(text);               //wpisanie tekstu do zaszyfrowania do tablicy bajtów
            IntPtr textPtr = Marshal.AllocHGlobal(text.Length * 2);         //alokacja pamięci dla zaszyfrowanego tekstu

            Marshal.Copy(textArray, 0, textPtr, text.Length);               //kopiowanie zawartości tablicy bajtów pod wskaźnik pokazujący na zaszyfrowany tekst
           
            for (int i = text.Length; i < text.Length * 2; i++)             //zerowanie przestrzeni, na której ma być zapisany zaszyfrowany tekst
            {
                Marshal.WriteByte(textPtr + i, 0);
            }
            
            if (cppRadioButton.Checked)                                     //sprawdzenie, która wersja biblioteki jest wybrana i wywołanie z niej funkcji szyfrującej
            {
                Program.encryptText(polybiusArray, textArray, textPtr, text.Length).ToString();
            }
            else if (asmRadioButton.Checked)
            {
                Program.encryptTextAsm(polybiusArray, textArray, textPtr, text.Length).ToString();
            }
            else
            {
                encrypted = "Encryption failed.";
            }
            

            byte[] resultByteArray = new byte[text.Length * 2];             //stworzenie nowej tablicy bajtów
            Marshal.Copy(textPtr, resultByteArray, 0, text.Length * 2);     //kopiowanie zawartości tablicy z zaszyfrowanym tekstem do nowej tablicy
            Marshal.FreeHGlobal(textPtr);                                   //zwolnienie pamięci
            encrypted = Encoding.ASCII.GetString(resultByteArray);          //rzutowanie zaszyfrowanego tekstu z tablicy bajtów na String
            return encrypted;                                               //zwrócenie zaszyfrowanego tekstu
        }




        //funkcja wywoływana po naciśnięciu przycisku Encrypt w oknie aplikacji
        private void encryptButton_Click(object sender, EventArgs e)
        {
            //pobranie słowa kluczowego
            bool validKeyword = false;                                  //inicjalizacja zmiennej warunkującej poprawność słowa kluczowego
            String keyword = keywordTextBox.Text.ToUpper();             //przekształcenie liter zmiennej na wielkie litery
            byte[] keywordArray = Encoding.ASCII.GetBytes(keyword);     //inicjalizacja zmiennej przechowującej słowo kluczowe w postaci tablicy bajtów
            if(Program.checkValidityOfKeyword(keywordArray))            //sprawdzenie, czy słowo kluczowe jest poprawne
            {
                validKeyword = true;
            }

            if (validKeyword)                                           //sprawdzenie, czy słowo kluczowe jest poprawne
            {
                keywordErrorLabel.Text = null;
            }
            else
            {
                keywordTextBox.Text = "Invalid keyword.";               //wyświetlenie komunikatów o niepoprawnym słowie kluczowym
                keywordErrorLabel.Text = "It should contain from 3 to 7 letters belonging to\nenglish alphabet.";
            }

            
            //pobranie tekstu do zaszyfrowania
            bool validText = false;                                 //inicjalizacja zmiennej warunkującej poprawność tekstu do zaszyfrowania
            String text = textRichTextBox.Text.ToUpper();           //przekształcenie liter zmiennej na wielkie litery
            byte[] textArray = Encoding.ASCII.GetBytes(text);       //inicjalizacja zmiennej przechowującej tekst do zaszyfrowania w postaci tablicy bajtów
            if (Program.checkCharactersInText(textArray))           //sprawdzenie, czy tekst do zaszyfrowania jest poprawny
            {
                validText = true;
            }

            if(validText)                                           //sprawdzenie, czy tekst do zaszyfrowania jest poprawny
            {            
                textErrorLabel.Text = null;
            }
            else
            {
                textRichTextBox.Text = "Invalid text.";             //wyświetlenie komunikatów o niepoprawnym tekście do zaszyfrowania
                textErrorLabel.Text = "It should contain only letters belonging to english\nalphabet or five special signs: space, dot, comma,\nquestion mark or exclamation mark.";
            }


            //pobranie liczby wątków
            bool validCount = false;     //inicjalizacja zmiennej warunkującej poprawność wybranej liczby wątków
            int count = Convert.ToInt32(Math.Round(threadNumericUpDown.Value, 0));
            if(count <= text.Length)     //sprawdzenie, czy liczba wątków jest poprawna
            {
                validCount = true;
            }

            if (validCount)
            {
                threadErrorLabel.Text = null;
            }
            else
            {
                threadErrorLabel.Text = "Number of threads should be\nless than or equal to the number\nof characters in text and not\ngreater than 64.";   //wyświetlenie komunikatu o niepoprawnej liczbie wątków
            }


            //sprawdzenie, czy słowo kluczowe, tekst do zaszyfrowania i liczba wątków są poprawne
            if (validKeyword == true && validText == true && validCount == true)
            {
                //stworzenie elementów potrzebnych do zarządzania pracą wątków
                Thread[] threadTable = new Thread[count];                       //stworzenie tablicy wątków
                Distributor distributor;                                        //deklaracja obiektu klasy Distributor umożliwiającego zarządzanie wątkami
                List<String> inputList = new List<String>();                    //stworzenie listy stringów do przechowywania fragmentów tekstu do zaszyfrowania w celu przekazania ich kolejnym wątkom
                
                //stworzenie szachownicy Polibiusza
                IntPtr polybiusArray = Marshal.AllocHGlobal(8 * 5);             //alokacja pamięci na 5 wskaźników
                IntPtr[] rowArray = new IntPtr[5];                              //stworzenie tablicy przechowującej 5 wskaźników
                for (int i = 0; i < 5; i++)                                     //alokacja pamięci na 11 bajtów dla wszystkich wskaźników
                {
                    rowArray[i] = Marshal.AllocHGlobal(1 * 11);
                    Marshal.WriteInt64(polybiusArray + i * 8, rowArray[i].ToInt64());
                }
                Program.createPolybiusSquare(polybiusArray, keywordArray);      //stworzenie szachownicy Polibiusza


                //przydzielenie każdemu wątkowi części tekstu do szyfrowania
                int textCount = text.Length;
                String currentText = null;

                if (count == textCount)                 //sprawdzenie, czy wybrana liczba wątków jest równa liczbie znaków w tekście do zaszyfrowania
                {
                    for (int i = 0; i < count; i++)     //podział tesktu do zaszyfrowania na liczbę części równą liczbie wątków
                    {
                        currentText = text[i].ToString();
                        inputList.Add(currentText);
                    }
                }

                else if (count < textCount)                             //sprawdzenie, czy wybrana liczba wątków jest mniejsza od liczby znaków w tekście do zaszyfrowania
                {
                    int remainder = 0, charCount = 0, counter = 0;      //inicjalizacja zmiennych potrzebnych do podziału tekstu do zaszyfrowania na części
                    remainder = textCount % count;                      //podział tekstu do zaszyfrowania na liczbę części równą liczbie wątków

                    if (remainder == 0)
                    {
                        charCount = textCount / count;
                        for (int i = 0; i < count; i++)
                        {
                            currentText = null;
                            for (int j = counter; j < (counter + charCount); j++)
                            {
                                currentText += text[j].ToString();
                            }
                            counter += charCount;
                            inputList.Add(currentText);
                        }
                    }
                    else if (remainder != 0)
                    {
                        charCount = textCount / count;
                        remainder = textCount - (charCount * count);

                        for (int i = 0; i < count; i++)
                        {
                            currentText = null;
                            for (int j = counter; j < (counter + charCount); j++)
                            {
                                currentText += text[j].ToString();
                            }
                            counter += charCount;
                            if (remainder != 0)
                            {
                                currentText += text[counter].ToString();
                                remainder--;
                                counter++;
                            }
                            inputList.Add(currentText);
                        }
                    }                    
                }

                distributor = new Distributor(inputList, count);    //stworzenie obiektu klasy Distributor zarządzającego pracą wątków

                //początek pomiaru czasu wykonywania szyfrowania
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                
                //uruchomienie wątków
                for (int i = 0; i < count; i++)
                {
                    threadTable[i] = new Thread(() => { threadEncrypt(distributor, polybiusArray); });
                    threadTable[i].Name = "Thread " + i;
                    threadTable[i].Start();
                }

                //zablokowanie wątków
                for (int i = 0; i < count; i++)
                {
                    threadTable[i].Join();
                }

                //wypisanie zaszyfrowanego tekstu w oknie aplikacji
                encryptedTextAnswerRichTextBox.Text = "";
                for (int i = 0; i < count; i++)
                {
                    encryptedTextAnswerRichTextBox.Text += distributor.stringTable[i];
                }

                //koniec pomiaru czasu wykonywania szyfrowania
                stopwatch.Stop();
                TimeSpan ts = stopwatch.Elapsed;
                double timeMs = ts.TotalMilliseconds;

                //wypisanie rezultatu pomiaru czasu w oknie aplikacji
                conversionTimeAnswerLabel.Text = timeMs.ToString();

                //
                for (int i = 0; i < 5; i++)
                {
                    Marshal.Copy(rowArray[i], square[i], 0, 11);
                    Marshal.FreeHGlobal(rowArray[i]);
                }
                Marshal.FreeHGlobal(polybiusArray);
            }
        }

        //funkcja wywołująca SIMDProcedure, ilustrująca działanie instrukcji wektorowych
        public float[] testSIMDProcedure()
        {
            const int tabsize = 80;                                     //ustalenie rozmiaru tablicy
            float[] tab1 = new float[tabsize / 4];                      //stworzenie pierwszej tablicy liczb 
            float[] tab2 = new float[tabsize / 4];                      //stworzenie drugiej tablicy liczb
            float[] tabres = new float[tabsize / 4];                    //stworzenie wynikowej tablicy liczb

            for (int i = 0; i < tabsize / 4; i++)                       //wypełnianie tablic liczb zawartością
            {
                tab1[i] = i * 2;
                tab2[i] = i;
            }

            if((tabsize % 16) == 0)                                     //sprawdzenie, czy rozmiar tablicy jest podzielny przez 16
            {
                Program.SIMDProcedure(tab1, tab2, tabres, tabsize);     //wywołanie funkcji ilustrującej działanie instrukcji wektorowych   
            }
            return tabres;                                              //zwrócenie tablicy wynikowej
        }


        //funkcja wywoływana po naciśnięciu etykiety Encrypted Text w oknie aplikacji
        private void encryptedTextLabel_Click(object sender, EventArgs e)
        {
            String result = "";
            
            for (int i = 0; i < testSIMDProcedure().Length; i++)    //konwersja rezulatatu działania funkcji SIMDProcesure na typ string
            {
                result += testSIMDProcedure()[i].ToString() + "\n";
            }
            encryptedTextAnswerRichTextBox.Text = result;           //wypisanie rezultatu działania funkcji SIMDProcedure w oknie aplikacji
        }
    }


    //klasa odpowiedzialna za zarządzanie wątkami
    class Distributor
    {
        List<String> inputList;             //lista zmiennych typu String odpowiedzialna za przechowywanie poszczególnych części tekstu do zaszyfrowania 
        Object semaphore = new Object();    //instancja klasy Object, warunkująca wykonywanie się fragmentu funkcji getCounter
        public String[] stringTable;        //tablica zmiennych typu String odpowiedzialna za przechowywanie poszczególnych części zaszyfrowanego tekstu
        int threadCount;                    //zmienna przechowująca liczbę wątków
        int counter = 0;                    //zmienna przechowująca licznik wątków

        //konstruktor obiektu klasy Distributor
        public Distributor(List<String> inputList, int threadCount)
        {
            stringTable = new string[threadCount];
            this.inputList = inputList;
            this.threadCount = threadCount;
        }

        //funkcja zwracająca wartość licznika wątków
        public int getCounter()
        {
            int s;
            lock (semaphore)
            {
                if (counter < threadCount)
                {
                    s = counter;
                    counter++;
                }
                else
                {
                    s = -1;
                }
            }
            return s;
        }

        //funkcja zwracająca fragment listy wejściowej spod konkretnego indeksu
        public String getString(int index)
        {
            return inputList[index];
        }

        //funkcja ustawiająca fragment tablicy z zaszyfrownaym tesktem pod konkretnym indeksem
        public void setResult(String s, int index)
        {
            stringTable[index] = s;
        }

    }

}
