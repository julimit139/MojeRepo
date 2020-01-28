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
		valid = true;										//zmiana warto�ci zmiennej valid na, gdy d�ugo�� zmiennej keyword zawiera si� w zakresie od 3 do 7 liter
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
extern "C" EXPORT std::string removeDuplicates(char* key)
{
	std::string keyword(key);
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	for (int i = 0; i < keyword.length(); i++)
	{
		for (int j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))
			{
				keyword.erase(keyword.begin() + j);
				j--;
			}
		}
	}
	return keyword;
}


//funkcja sprawdzaj�ca poprawno�� podanego s�owa kluczowego
extern "C" EXPORT bool checkValidityOfKeyword(char* key)
{
	bool valid = false;
	if (checkCharactersInKeyword(key))
	{
		if (checkDuplicatesInKeyword(key))
		{
			if (checkLengthOfKeyword(key))
			{
				valid = true;
			}
		}
		else
		{
			std::string(keyword) = removeDuplicates(key);
			if (checkLengthOfKeyword(&keyword[0]))
			{
				valid = true;
			}
		}
	}
	return valid;
}

//funkcja tworz�ca szachownic� Polibiusza na podstawie podanego s�owa kluczowego 
extern "C" EXPORT void createPolybiusSquare(char** square, char* key)
{
	/*char** square = new char*[HEIGHT];  
	for (int i = 0; i < HEIGHT; ++i)
	{
		square[i] = new char[WIDTH];
	}*/

	std::string keyword(key);
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	std::string newAlphabet = alphabet; //creating new alphabet
	for (int i = 0; i < keyword.length(); i++) //removing letters forming keyword from new alphabet  
	{
		char letter = keyword.at(i);
		newAlphabet.erase(std::remove(newAlphabet.begin(), newAlphabet.end(), letter), newAlphabet.end());
	}

	newAlphabet = newAlphabet + specialSigns; //adding special signs to new alphabet

	//writing stars, numerals, letters and special signs to array - in accordance with ASCII code
	square[0][0] = square[1][0] = '*'; //writing stars to the array

	for (int j = 1; j < (WIDTH - 1); j++)
	{
		square[0][j] = j + 48; //writing numerals to the array
	}
	square[0][10] = 48;

	for (int i = 2; i < HEIGHT; i++)
	{
		square[i][0] = keyword.length() - 1 + i + 48; //writing numerals to the array
		if ((keyword.length() == 7) && (i == 4))
		{
			square[i][0] = keyword.length() - 1 + i - 10 + 48;
		}
	}

	for (int j = 1; j < (keyword.length() + 1); j++)
	{
		square[1][j] = keyword.at(j - 1); //writing keyword to the array
	}

	for (int j = (keyword.length() + 1); j < WIDTH; j++)
	{
		square[1][j] = '*'; //writing stars to the array
	}

	int iterator = 0;
	for (int i = 2; i < HEIGHT; i++) //writing new alphabet to the array
	{
		if (i != 4)
		{
			for (int j = 1; j < WIDTH; j++)
			{
				square[i][j] = newAlphabet.at(iterator);
				iterator++;
			}
		}
		else
		{
			for (int j = 1; j < (WIDTH - keyword.length() + 1); j++)
			{
				square[i][j] = newAlphabet.at(iterator);
				iterator++;
			}
			for (int j = (WIDTH - keyword.length() + 1); j < WIDTH; j++)
			{
				square[i][j] = '*'; //writing stars to the array
			}
		}
	}
}

//funkcja sprawdzaj�ca, czy znaki tworz�ce podany tekst nale�� do angielskiego alfabetu lub grupy znak�w specjalnych
extern "C" EXPORT bool checkCharactersInText(char* text)
{
	std::string textword(text);
	std::transform(textword.begin(), textword.end(), textword.begin(), ::toupper);
	bool valid = false;
	for (int i = 0; i < textword.length(); i++)
	{
		if (improvedAlphabet.find(textword.at(i)) != std::string::npos)
		{
			valid = true;
		}
		else
		{
			valid = false;
			break;
		}
	}
	return valid;
}

//funkcja szyfruj�ca podany tekst na podstawie stworzonej szachownicy Polibiusza
extern "C" EXPORT bool encryptText(char** square, char* text, char* output, int arrayLength)
{
	std::string found = "";
	std::string textword = "";
	textword = std::string(text);

	char letter;
	for (int k = 0; k < textword.length(); k++)
	{
		letter = textword.at(k);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (square[i][j] == letter)
				{
					if (i != 1)
					{
						found += std::to_string(square[i][0] - 48);
					}
					found += std::to_string(square[0][j] - 48);
					break;
				}
			}
		}
	}
	char* foundPtr = (char*)found.c_str();
	for (int i = 0; i < found.length(); i++)
	{
		*(output + i) = *(foundPtr + i);
	}
	return true;
}