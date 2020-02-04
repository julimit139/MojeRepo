// PolybiusSquareCpp.cpp : Defines the exported functions for the DLL application.


//do��czenie pliku nag��wkowego zawieraj�cego deklaracje funkcji zdefiniowanych poni�ej
#include "PolybiusSquareCpp.h"


//funkcja sprawdzaj�ca, czy d�ugo�� podanego s�owa kluczowego nale�y do zakresu od 3 do 7 liter
extern "C" EXPORT bool checkLengthOfKeyword(char* key)		//parametrem funkcji jest podane s�owo kluczowe typu char*
{
	std::string keyword(key);								//przekszta�cenie zmiennej typu char* na typ string
	bool valid = false;										//inicjalizacja zmiennej valid warunkuj�cej poprawno�� s�owa kluczowego
	if ((keyword.length() > 2) && (keyword.length() < 8))	//sprawdzenie d�ugo�ci s�owa kluczowego
	{
		valid = true;										//zmiana warto�ci zmiennej valid, gdy d�ugo�� zmiennej keyword zawiera si� w zakresie od 3 do 7 liter
	}
	return valid;											//zwr�cenie warto�ci zmiennej valid
}



//funkcja sprawdzaj�ca, czy litery tworz�ce podane s�owo kluczowe nale�� do angielskiego alfabetu
extern "C" EXPORT bool checkCharactersInKeyword(char* key)							//parametrem funkcji jest podane s�owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta�cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta�cenie wszystkich liter nale��cych do podanego s�owa kluczowego na wielkie litery
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj�cej poprawno�� s�owa kluczowego
	for (int i = 0; i < keyword.length(); i++)										//p�tla, w kt�rej sprawdzane s� litery
	{
		if (alphabet.find(keyword.at(i)) != std::string::npos)						//sprawdzenie, czy litera nale�y do alfabetu angielskiego
		{
			valid = true;															//zmiana warto�ci zmiennej valid
		}
		else
		{
			valid = false;															//zmiana warto�ci zmiennej valid
			break;																	//przerwanie p�tli for
		}
	}
	return valid;																	//zwr�cenie warto�ci zmiennej valid
}



//funkcja sprawdzaj�ca, czy podane s�owo kluczowe zawiera powtarzaj�ce si� litery
extern "C" EXPORT bool checkDuplicatesInKeyword(char* key)							//parametrem funkcji jest podane s�owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta�cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta�cenie wszystkich liter na wielkie litery
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj�cej poprawno�� s�owa kluczowego
	int p = -1, i, j;																//inicjalizacja zmiennej p przechowuj�cej indeks zduplikowanej litery i deklaracja zmiennych i i j s�u��cych do realizacji dw�ch p�tli for
	for (i = 0; i < keyword.length(); i++)											//p�tle, w kt�rych sprawdzane jest, czy litery si� powtarzaj�
	{
		for (j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))										//sprawdzenie, czy litera na pozycji i-tej jest taka sama jak litera na pozycji j-tej
			{
				p = i;																//zmiana warto�ci zmiennej p na indeks sprawdzanej litery
				break;																//przerwanie p�tli for 
			}
		}
		if (p != -1)																//sprawdzenie, czy litera na pozycji i-tej powtarza si�
		{
			break;																	//przerwanie p�tli for
		}
	}

	if (p == -1)																	//sprawdzenie, czy kt�rakolwiek z liter si� powtarza
	{
		valid = true;																//zmiana warto�ci zmiennej valid
	}

	return valid;																	//zwr�cenie warto�ci zmiennej valid
}

//funkcja usuwaj�ca powtarzaj�ce si� litery z podanego s�owa kluczowego
extern "C" EXPORT std::string removeDuplicates(char* key)							//parametrem funkcji jest podane s�owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta�cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta�cenie wszystkich liter na wielkie litery
	for (int i = 0; i < keyword.length(); i++)										//p�tle, w kt�rych usuwane s� powtarzaj�ce si� litery
	{
		for (int j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))										//sprawdzenie, czy litera na pozycji i-tej jest taka sama jak litera na pozycji j-tej

			{
				keyword.erase(keyword.begin() + j);									//usuni�cie litery z pozycji j-tej
				j--;
			}
		}
	}
	return keyword;																	//zwr�cenie s�owa kluczowego
}


//funkcja sprawdzaj�ca poprawno�� podanego s�owa kluczowego
extern "C" EXPORT bool checkValidityOfKeyword(char* key)							//parametrem funkcji jest podane s�owo kluczowe typu char*
{
	bool valid = false;																//inicjalizacja zmiennej valid warunkuj�cej poprawno�� s�owa kluczowego
	if (checkCharactersInKeyword(key))												//sprawdzenie, czy litery tworz�ce s�owo kluczowe nale�� do angielskiego alfabetu
	{
		if (checkDuplicatesInKeyword(key))											//sprawdzenie, czy s�owo kluczowe zawiera powtarzaj�ce si� litery
		{
			if (checkLengthOfKeyword(key))											//sprawdzenie, czy d�ugo�� s�owa kluczowego nale�y do zakresu od 3 do 7 liter
			{
				valid = true;														//zmiana warto�ci zmiennej valid
			}
		}
		else
		{
			std::string(keyword) = removeDuplicates(key);							//usuni�cie powtarzaj�cyh si� liter ze s�owa kluczowego
			if (checkLengthOfKeyword(&keyword[0]))									//sprawdzenie, czy d�ugo�� s�owa kluczowego nale�y do zakresu od 3 do 7 liter
			{
				valid = true;														//zmiana warto�ci zmiennej valid
			}
		}
	}
	return valid;																	//zwr�cenie warto�ci zmiennej valid
}

//funkcja tworz�ca szachownic� Polibiusza na podstawie podanego s�owa kluczowego 
extern "C" EXPORT void createPolybiusSquare(char** square, char* key)				//parametrami funkcji s� szachownica Polibiusza typu char** i s�owo kluczowe typu char*
{
	std::string keyword(key);														//przekszta�cenie zmiennej typu char* na typ string
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);		//przekszta�cenie wszystkich liter zmiennej keyword na wielkie litery
	std::string newAlphabet = alphabet;												//inicjalizacja zmiennej newAlphabet warto�ci� zmiennej alphabet, przechowuj�c� litery alfabetu angielskiego
	for (int i = 0; i < keyword.length(); i++)										//p�tla iteruj�ca po kolejnych literach s�owa kluczowego
	{
		char letter = keyword.at(i);												//przypisanie zmiennej letter litery na pozycji i-tej s�owa kluczowego
		newAlphabet.erase(std::remove(newAlphabet.begin(), newAlphabet.end(), letter), newAlphabet.end());//usuni�cie warto�ci zmiennej letter ze zmiennej newAlphabet
	}

	newAlphabet = newAlphabet + specialSigns;										//dodanie znak�w specjalnych do zmiennej newAlphabet

	//uzupe�nianie szachownicy Polibiusza odpowiednimi warto�ciami - zgodnie z kodem ASCII
	square[0][0] = square[1][0] = '*';												//wpisywanie gwiazdek oznaczaj�cych puste miejsca do szachownicy Polibiusza

	for (int j = 1; j < (WIDTH - 1); j++)											//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[0][j] = j + 48;														//wpisywanie cyfr numeruj�cych kolumny do szachownicy Polibiusza
	}
	square[0][10] = 48;

	for (int i = 2; i < HEIGHT; i++)												//p�tla iteruj�ca po kolejnych wierszach szachownicy Polibiusza
	{
		square[i][0] = keyword.length() - 1 + i + 48;								//wpisywanie cyfr numeruj�cych wiersze do szachownicy Polibiusza
		if ((keyword.length() == 7) && (i == 4))
		{
			square[i][0] = keyword.length() - 1 + i - 10 + 48;
		}
	}

	for (int j = 1; j < (keyword.length() + 1); j++)								//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[1][j] = keyword.at(j - 1);											//wpisywanie s�owa kluczowego do szachownicy Polibiusza
	}

	for (int j = (keyword.length() + 1); j < WIDTH; j++)							//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
	{
		square[1][j] = '*';															//wpisywanie gwiazdek do szachownicy Polibiusza
	}

	int iterator = 0;																//inicjalizacja zmiennej iterator iteruj�cej po zmiennej newAlphabet warto�ci� 0
	for (int i = 2; i < HEIGHT; i++)												//p�tla iteruj�ca po kolejnych wierszach szachownicy Polibiusza
	{
		if (i != 4)																	//sprawdzenie, czy indeks wiersza jest r�wny 4
		{
			for (int j = 1; j < WIDTH; j++)											//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = newAlphabet.at(iterator);							//wpisywanie zmiennej newAlphabet do szachownicy Polibiusza
				iterator++;															//inkrementacja zmiennej iterator
			}
		}
		else
		{
			for (int j = 1; j < (WIDTH - keyword.length() + 1); j++)				//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = newAlphabet.at(iterator);							//wpisywanie zmiennej newAlphabet do szachownicy Polibiusza
				iterator++;															//inkrementacja zmiennej iterator
			}
			for (int j = (WIDTH - keyword.length() + 1); j < WIDTH; j++)			//p�tla iteruj�ca po kolejnych kolumnach szachownicy Polibiusza
			{
				square[i][j] = '*';													//wpisywanie gwiazdek do szachownicy Polibiusza 
			}
		}
	}
}

//funkcja sprawdzaj�ca, czy znaki tworz�ce podany tekst nale�� do angielskiego alfabetu lub grupy znak�w specjalnych
extern "C" EXPORT bool checkCharactersInText(char* text)								//parametrem funkcji jest podany tekst do zaszyfrowania typu char*
{
	std::string textword(text);															//przekszta�cenie zmiennej typu char* na typ string
	std::transform(textword.begin(), textword.end(), textword.begin(), ::toupper);		//przekszta�cenie wszystkich liter na wielkie litery
	bool valid = false;																	//inicjalizacja zmiennej valid warunkuj�cej poprawno�� tekstu do zaszyfrowania
	for (int i = 0; i < textword.length(); i++)											//p�tla, w kt�rej sprawdzane s� znaki
	{
		if (improvedAlphabet.find(textword.at(i)) != std::string::npos)					//sprawdzenie, czy znak nale�y do alfabetu angielskiego lub grupy znak�w specjalnych
		{
			valid = true;																//zmiana warto�ci zmiennej valid
		}
		else
		{
			valid = false;																//zmiana warto�ci zmiennej valid
			break;																		//przerwanie p�tli for
		}
	}
	return valid;																		//zwr�cenie warto�ci zmiennej valid
}

//funkcja szyfruj�ca podany tekst na podstawie stworzonej szachownicy Polibiusza
extern "C" EXPORT bool encryptText(char** square, char* text, char* output, int arrayLength)	//parametrami funkcji s� szachownica Polibiusza typu char**, podany tekst do zaszyfrowania typu char*, zaszyfrownay tekst typu char* i d�ugo�� tekstu do zaszyfrowania typu int
{
	std::string found = "";																		//inicjalizacja zmiennej found przechowuj�cej zaszyfrowany tekst pustym napisem
	std::string textword = "";																	//inicjalizacja zmiennej textword przechowuj�cej tekst do zaszyfrowania pustym napisem
	textword = std::string(text);																//przekszta�cenie zmiennej typu char* na typ string

	char letter;																				//deklaracja zmiennej letter przechowuj�cej kolejne litery tekstu do zaszyfrowania 
	for (int k = 0; k < textword.length(); k++)													//p�tla iteruj�ca po kolejnych literach tekstu do zaszyfrowania
	{
		letter = textword.at(k);																//przypisanie zmiennej letter litery znajduj�cej si� na k-tej pozycji w tek�cie do zaszyfrowania
		for (int i = 0; i < height; i++)														//p�tla iteruj�ca po kolejnych wierszach tablicy Polibiusza
		{
			for (int j = 0; j < width; j++)														//p�tla iteruj�ca po kolejnych kolumnach tablicy Polibiusza
			{
				if (square[i][j] == letter)														//sprawdzenie, czy warto�� tablicy Polibiusza w i-tym wierszu i j-tej kolumnie jest taka sama jak warto�� zmiennej letter
				{
					if (i != 1)																	//sprawdzenie, czy indeks wiersza jest r�wny 1, co oznacza, �e litera nale�y do s�owa kluczowego
					{
						found += std::to_string(square[i][0] - 48);								//dodanie do zmiennej found znaku rzutowanego na typ string, znajduj�cego si� w i-tym wierszu i kolumnie o indeksie r�wnym 0 w tablicy Polibiusza
					}
					found += std::to_string(square[0][j] - 48);									//dodanie do zmiennej found znaku rzutowanego na typ string, znajduj�cego si� w wierszu o indeksie r�wnym 0 i j-tej kolumnie w tablicy Polibiusza
					break;																		//przerwanie p�tli for
				}
			}
		}
	}
	char* foundPtr = (char*)found.c_str();														//rzutowanie zmiennej found na typ char* 
	for (int i = 0; i < found.length(); i++)													//p�tla iteruj�ca po kolejnych znakach zmiennej found
	{
		*(output + i) = *(foundPtr + i);														//przypisanie kolejnym elementom zmiennej output kolejnych znak�w zmiennej foundPtr
	}
	return true;																				//zwr�cenie warto�ci true
}