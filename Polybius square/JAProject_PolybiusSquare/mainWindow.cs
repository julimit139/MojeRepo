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
        byte[][] square;

        public mainWindow()
        {
            square = new byte[5][];
            for(int i = 0; i < 5; i++)
            {
                square[i] = new byte[11];
            }
            InitializeComponent();
        }



        private String encrypt(String text, IntPtr initArray)
        {
            String encrypted = null;
            byte[] textArray = Encoding.ASCII.GetBytes(text);
            IntPtr textPtr = Marshal.AllocHGlobal(text.Length * 2);

            Marshal.Copy(textArray, 0, textPtr, text.Length);
           
            for (int i = text.Length; i < text.Length * 2; i++)
            {

                Marshal.WriteByte(textPtr + i, 0);
            }

            
            if (cppRadioButton.Checked)
            {
                Program.encryptTextAsm(initArray, textArray, textPtr, text.Length).ToString();
            }
            else if (asmRadioButton.Checked)
            {
                //encrypt asm
            }
            else
            {
                encrypted = "Encryption failed.";
            }
            

            byte[] resultByteArray = new byte[text.Length * 2];
            Marshal.Copy(textPtr, resultByteArray, 0, text.Length * 2);
            //encryptedTextAnswerRichTextBox.Text = Encoding.ASCII.GetString(resultByteArray);
            encrypted = Encoding.ASCII.GetString(resultByteArray);
            Marshal.FreeHGlobal(textPtr);

            return encrypted;
        }





        private void encryptButton_Click(object sender, EventArgs e)
        {
            


            //pobranie słowa kluczowego
            bool validKeyword = true;
            String keyword = keywordTextBox.Text.ToUpper();
            byte[] keywordArray = Encoding.ASCII.GetBytes(keyword);
            if(!Program.checkValidityOfKeyword(keywordArray))
            {
                keywordTextBox.Text = "Given keyword is invalid.";
                validKeyword = false;
            }


            //pobranie tekstu do szyfrowania
            bool validText = true;
            String text = textRichTextBox.Text.ToUpper();
            byte[] textArray = Encoding.ASCII.GetBytes(text);
            if(!Program.checkCharactersInText(textArray))
            {
                textRichTextBox.Text = "Given text is invalid.";
                validText = false;
            }


            //pobranie liczby wątków
            bool validCount = true;
            int count = Convert.ToInt32(Math.Round(threadNumericUpDown.Value, 0));
            if(count > text.Length)
            {
                //wyświetlić komunikat o błędzie!!!
                validCount = false;
            }


            if (validKeyword == true && validText == true && validCount == true)
            {

                //stworzenie tablicy wątków
                Thread[] threadTable = new Thread[count];
                String[] stringTable = new String[count];
                //String[] textTable = new String[count];

                Distributor distributor;

                List<String> stringList = new List<String>();
                

                //tworzenie szachownicy Polibiusza
                IntPtr initArray = Marshal.AllocHGlobal(8 * 5); //Alokacja pamięci na 5 wskaźników
                IntPtr[] arrayArray = new IntPtr[5];
                for (int i = 0; i < 5; i++)
                {
                    arrayArray[i] = Marshal.AllocHGlobal(11); //Alokacja pamięci na 11 bajtów
                    Marshal.WriteInt64(initArray + i * 8, arrayArray[i].ToInt64());
                }
                Program.createPolybiusSquare(initArray, keywordArray);


                String test = encrypt(text, initArray);

                //timer start
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();


                //przydzielenie każdemu wątkowi części tekstu do szyfrowania
                int textCount = text.Length;
                String currentText = null;
                if (count == textCount)
                {
                    for (int i = 0; i < count; i++)
                    {
                        currentText = text[i].ToString();
                        stringList.Add(currentText);
                    }
                }

                else if (count < textCount)
                {
                    int remainder = 0, charCount = 0, counter = 0;
                    remainder = textCount % count;

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
                            stringList.Add(currentText);
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
                            stringList.Add(currentText);
                        }

                    }

                    distributor = new Distributor(stringList, count);


                    for (int i = 0; i < count; i++)
                    {
                        threadTable[i] = new Thread(() => { stringTable[i] = encrypt(distributor.getString(), initArray); });
                        threadTable[i].Start();
                    }
                }


                
               

               //for (int i = 0; i < count; i++)
               // {
                    //threadTable[i] = new Thread(() => encrypt(text, initArray));
               //     encryptedTextAnswerRichTextBox.Text = threadTable[i].ToString();
               // }


                
                

                for (int i = 0; i < count; i++)
                {
                    threadTable[i].Join();
                }


              


                //timer stop
                stopwatch.Stop();
                TimeSpan ts = stopwatch.Elapsed;
                double timeMs = ts.TotalMilliseconds;

                conversionTimeAnswerLabel.Text = timeMs.ToString();



                
                for (int i = 0; i < 5; i++)
                {
                    Marshal.Copy(arrayArray[i], square[i], 0, 11);
                    Marshal.FreeHGlobal(arrayArray[i]);
                }
                Marshal.FreeHGlobal(initArray);
            }
        }
    }

    class Distributor
    {
        List<String> stringList;
        Object semaphore = new Object();
        int threadCount;
        int counter = 0;

        public Distributor(List<String> stringList, int threadCount)
        {
            this.stringList = stringList;
            this.threadCount = threadCount;
        }

        public String getString()
        {
            String s;
            lock (semaphore)
            {
                if(counter < threadCount)
                {
                    s = stringList[counter];
                    counter++;
                }
                else
                {
                    s = null;
                }
            }
            return s;
        }
    }

}
