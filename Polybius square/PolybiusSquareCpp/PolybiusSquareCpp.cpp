// PolybiusSquareCpp.cpp : Defines the exported functions for the DLL application.


//do³¹czenie pliku nag³ówkowego zawieraj¹cego deklaracje funkcji zdefiniowanych poni¿ej
#include "PolybiusSquareCpp.h"


//funkcja sprawdzaj¹ca, czy d³ugoœæ podanego s³owa kluczowego nale¿y do zakresu od 3 do 7 liter
extern "C" EXPORT bool checkLengthOfKeyword(char* key)		//parametrem funkcji jest podane s³owo kluczowe typu char*
{
	std::string keyword(key);								//przekszta³cenie zmiennej typu char* na typ string
	bool valid = false;										//inicjalizacja zmiennej valid warunkuj¹cej poprawnoœæ s³owa kluczowego
	if ((keyword.length() > 2) && (keyword.length() < 8))	//sprawdzenie d³ugoœci s³owa kluczowego
	{
		valid = true;										//zmiana wartoœci zmiennej valid, gdy d³ugoœæ zmiennej keyword zawiera siê w zakresie od 3 do 7 liter
	}
	return valid;											//zwrócenie wartoœci zmiennej valid
}



//funkcja sprawdzaj¹ca, czy litery tworz¹ce podane s³owo kluczowe nale¿¹ do angielskiego alfabetu
extern "C" EXPORT bool checkCharactersInKeyword(char* key)							//parametrem funkcji jest podane s³owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta³cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta³cenie wszystkich liter nale¿¹cych do podanego s³owa kluczowego na wielkie litery
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj¹cej poprawnoœæ s³owa kluczowego
	for (int i = 0; i < keyword.length(); i++)										//pêtla, w której sprawdzane s¹ litery
	{
		if (alphabet.find(keyword.at(i)) != std::string::npos)						//sprawdzenie, czy litera nale¿y do alfabetu angielskiego
		{
			valid = true;															//zmiana wartoœci zmiennej valid
		}
		else
		{
			valid = false;															//zmiana wartoœci zmiennej valid
			break;																	//przerwanie pêtli for
		}
	}
	return valid;																	//zwrócenie wartoœci zmiennej valid
}



//funkcja sprawdzaj¹ca, czy podane s³owo kluczowe zawiera powtarzaj¹ce siê litery
extern "C" EXPORT bool checkDuplicatesInKeyword(char* key)							//parametrem funkcji jest podane s³owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta³cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta³cenie wszystkich liter na wielkie litery
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj¹cej poprawnoœæ s³owa kluczowego
	int p = -1, i, j;																//inicjalizacja zmiennej p przechowuj¹cej indeks zduplikowanej litery i deklaracja zmiennych i i j s³u¿¹cych do realizacji dwóch pêtli for
	for (i = 0; i < keyword.length(); i++)											//pêtle, w których sprawdzane jest, czy litery siê powtarzaj¹
	{
		for (j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))										//sprawdzenie, czy litera na pozycji i-tej jest taka sama jak litera na pozycji j-tej
			{
				p = i;																//zmiana wartoœci zmiennej p na indeks sprawdzanej litery
				break;																//przerwanie pêtli for 
			}
		}
		if (p != -1)																//sprawdzenie, czy litera na pozycji i-tej powtarza siê
		{
			break;																	//przerwanie pêtli for
		}
	}

	if (p == -1)																	//sprawdzenie, czy którakolwiek z liter siê powtarza
	{
		valid = true;																//zmiana wartoœci zmiennej valid
	}

	return valid;																	//zwrócenie wartoœci zmiennej valid
}

//funkcja usuwaj¹ca powtarzaj¹ce siê litery z podanego s³owa kluczowego
extern "C" EXPORT std::string removeDuplicates(char* key)							//parametrem funkcji jest podane s³owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta³cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta³cenie wszystkich liter na wielkie litery
	for (int i = 0; i < keyword.length(); i++)										//pêtle, w których usuwane s¹ powtarzaj¹ce siê litery
	{
		for (int j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))										//sprawdzenie, czy litera na pozycji i-tej jest taka sama jak litera na pozycji j-tej

			{
				keyword.erase(keyword.begin() + j);									//usuniêcie litery z pozycji j-tej
				j--;
			}
		}
	}
	return keyword;																	//zwrócenie s³owa kluczowego
}


//funkcja sprawdzaj¹ca poprawnoœæ podanego s³owa kluczowego
extern "C" EXPORT bool checkValidityOfKeyword(char* key)							//parametrem funkcji jest podane s³owo kluczowe typu char*
{
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj¹cej poprawnoœæ s³owa kluczowego
	if (checkCharactersInKeyword(key))												//sprawdzenie, czy litery tworz¹ce s³owo kluczowe nale¿¹ do angielskiego alfabetu
	{
		if (checkDuplicatesInKeyword(key))											//sprawdzenie, czy s³owo kluczowe zawiera powtarzaj¹ce siê litery
		{
			if (checkLengthOfKeyword(key))											//sprawdzenie, czy d³ugoœæ s³owa kluczowego nale¿y do zakresu od 3 do 7 liter
			{
				valid = true;														//zmiana wartoœci zmiennej valid
			}
		}
		else
		{
			std::string(keyword) = removeDuplicates(key);							//usuniêcie powtarzaj¹cyh siê liter ze s³owa kluczowego
			if (checkLengthOfKeyword(&keyword[0]))									//sprawdzenie, czy d³ugoœæ s³owa kluczowego nale¿y do zakresu od 3 do 7 liter
			{
				valid = true;														//zmiana wartoœci zmiennej valid
			}
		}
	}
	return valid;																	//zwrócenie wartoœci zmiennej valid
}

//funkcja tworz¹ca szachownicê Polibiusza na podstawie podanego s³owa kluczowego 
extern "C" EXPORT void createPolybiusSquare(char** square, char* key)				//parametrami funkcji s¹ szachownica Polibiusza typu char** i s³owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta³cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta³cenie wszystkich liter zmiennej keyword na wielkie litery
	std::string newAlphabet = alphabet;												//inicjalizacja zmiennej newAlphabet wartoœci¹ zmiennej alphabet, przechowuj¹c¹ litery alfabetu angielskiego
	for (int i = 0; i < keyword.length(); i++)										//pêtla iteruj¹ca po kolejnych literach s³owa kluczowego
	{
		char letter = keyword.at(i);												//przypisanie zmiennej letter litery na pozycji i-tej s³owa kluczowego
		newAlphabet.erase(std::remove(newAlphabet.begin(), newAlphabet.end(), letter), newAlphabet.end());//usuniêcie wartoœci zmiennej letter ze zmiennej newAlphabet
	}

	newAlphabet = newAlphabet + specialSigns;										//dodanie znaków specjalnych do zmiennej newAlphabet

	//uzupe³nianie szachownicy Polibiusza odpowiednimi wartoœciami - zgodnie z kodem ASCII
	square[0][0] = square[1][0] = '*';												//wpisywanie gwiazdek oznaczaj¹cych puste miejsca do szachownicy Polibiusza

	for (int j = 1; j < (WIDTH - 1); j++)											//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[0][j] = j + 48;														//wpisywanie cyfr numeruj¹cych kolumny do szachownicy Polibiusza
	}
	square[0][10] = 48;

	for (int i = 2; i < HEIGHT; i++)												//pêtla iteruj¹ca po kolejnych wierszach szachownicy Polibiusza
	{
		square[i][0] = keyword.length() - 1 + i + 48;								//wpisywanie cyfr numeruj¹cych wiersze do szachownicy Polibiusza
		if ((keyword.length() == 7) && (i == 4))
		{
			square[i][0] = keyword.length() - 1 + i - 10 + 48;
		}
	}

	for (int j = 1; j < (keyword.length() + 1); j++)								//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[1][j] = keyword.at(j - 1);											//wpisywanie s³owa kluczowego do szachownicy Polibiusza
	}

	for (int j = (keyword.length() + 1); j < WIDTH; j++)							//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[1][j] = '*';															//wpisywanie gwiazdek do szachownicy Polibiusza
	}

	int iterator = 0;																//inicjalizacja zmiennej iterator iteruj¹cej po zmiennej newAlphabet wartoœci¹ 0
	for (int i = 2; i < HEIGHT; i++)												//pêtla iteruj¹ca po kolejnych wierszach szachownicy Polibiusza
	{
		if (i != 4)																	//sprawdzenie, czy indeks wiersza jest równy 4
		{
			for (int j = 1; j < WIDTH; j++)											//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = newAlphabet.at(iterator);							//wpisywanie zmiennej newAlphabet do szachownicy Polibiusza
				iterator++;															//inkrementacja zmiennej iterator
			}
		}
		else
		{
			for (int j = 1; j < (WIDTH - keyword.length() + 1); j++)				//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = newAlphabet.at(iterator);							//wpisywanie zmiennej newAlphabet do szachownicy Polibiusza
				iterator++;															//inkrementacja zmiennej iterator
			}
			for (int j = (WIDTH - keyword.length() + 1); j < WIDTH; j++)			//pêtla iteruj¹ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = '*';													//wpisywanie gwiazdek do szachownicy Polibiusza 
			}
		}
	}
}

//funkcja sprawdzaj¹ca, czy znaki tworz¹ce podany tekst nale¿¹ do angielskiego alfabetu lub grupy znaków specjalnych
extern "C" EXPORT bool checkCharactersInText(char* text)								//parametrem funkcji jest podany tekst do zaszyfrowania typu char*
{
	std::string textword(text);															//przekszta³cenie zmiennej typu char* na typ string
	std::transform(textword.begin(), textword.end(), textword.begin(), ::toupper);		//przekszta³cenie wszystkich liter na wielkie litery
	bool valid = false;																	//inicjalizacja zmiennej valid warunkuj¹cej poprawnoœæ tekstu do zaszyfrowania
	for (int i = 0; i < textword.length(); i++)											//pêtla, w której sprawdzane s¹ znaki
	{
		if (improvedAlphabet.find(textword.at(i)) != std::string::npos)					//sprawdzenie, czy znak nale¿y do alfabetu angielskiego lub grupy znaków specjalnych
		{
			valid = true;																//zmiana wartoœci zmiennej valid
		}
		else
		{
			valid = false;																//zmiana wartoœci zmiennej valid
			break;																		//przerwanie pêtli for
		}
	}
	return valid;																		//zwrócenie wartoœci zmiennej valid
}

//funkcja szyfruj¹ca podany tekst na podstawie stworzonej szachownicy Polibiusza
extern "C" EXPORT bool encryptText(char** square, char* text, char* output, int arrayLength)	//parametrami funkcji s¹ szachownica Polibiusza typu char**, podany tekst do zaszyfrowania typu char*, zaszyfrownay tekst typu char* i d³ugoœæ tekstu do zaszyfrowania typu int
{
	std::string found = "";																		//inicjalizacja zmiennej found przechowuj¹cej zaszyfrowany tekst pustym napisem
	std::string textword = "";																	//inicjalizacja zmiennej textword przechowuj¹cej tekst do zaszyfrowania pustym napisem
	textword = std::string(text);																//przekszta³cenie zmiennej typu char* na typ string

	char letter;																				//deklaracja zmiennej letter przechowuj¹cej kolejne litery tekstu do zaszyfrowania 
	for (int k = 0; k < textword.length(); k++)													//pêtla iteruj¹ca po kolejnych literach tekstu do zaszyfrowania
	{
		letter = textword.at(k);																//przypisanie zmiennej letter litery znajduj¹cej siê na k-tej pozycji w tekœcie do zaszyfrowania
		for (int i = 0; i < height; i++)														//pêtla iteruj¹ca po kolejnych wierszach tablicy Polibiusza
		{
			for (int j = 0; j < width; j++)														//pêtla iteruj¹ca po kolejnych kolumnach tablicy Polibiusza
			{
				if (square[i][j] == letter)														//sprawdzenie, czy wartoœæ tablicy Polibiusza w i-tym wierszu i j-tej kolumnie jest taka sama jak wartoœæ zmiennej letter
				{
					if (i != 1)																	//sprawdzenie, czy indeks wiersza jest równy 1, co oznacza, ¿e litera nale¿y do s³owa kluczowego
					{
						found += std::to_string(square[i][0] - 48);								//dodanie do zmiennej found znaku rzutowanego na typ string, znajduj¹cego siê w i-tym wierszu i kolumnie o indeksie równym 0 w tablicy Polibiusza
					}
					found += std::to_string(square[0][j] - 48);									//dodanie do zmiennej found znaku rzutowanego na typ string, znajduj¹cego siê w wierszu o indeksie równym 0 i j-tej kolumnie w tablicy Polibiusza
					break;																		//przerwanie pêtli for
				}
			}
		}
	}
	char* foundPtr = (char*)found.c_str();														//rzutowanie zmiennej found na typ char* 
	for (int i = 0; i < found.length(); i++)													//pêtla iteruj¹ca po kolejnych znakach zmiennej found
	{
		*(output + i) = *(foundPtr + i);														//przypisanie kolejnym elementom zmiennej output kolejnych znaków zmiennej foundPtr
	}
	return true;																				//zwrócenie wartoœci true
}