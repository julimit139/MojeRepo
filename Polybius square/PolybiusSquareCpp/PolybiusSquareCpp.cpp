// PolybiusSquareCpp.cpp : Defines the exported functions for the DLL application.
//

#include "PolybiusSquareCpp.h"

//correct
extern "C" EXPORT bool checkLengthOfKeyword(char* key)
{
	std::string keyword(key);
	bool valid = false;
	if ((keyword.length() > 2) && (keyword.length() < 8))
	{
		valid = true;
	}
	return valid;
}

//correct
extern "C" EXPORT bool checkCharactersInKeyword(char* key)
{
	std::string keyword(key);
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	bool valid = false;
	for (int i = 0; i < keyword.length(); i++)
	{
		if (alphabet.find(keyword.at(i)) != std::string::npos)
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

//correct
extern "C" EXPORT bool checkDuplicatesInKeyword(char* key)
{
	std::string keyword(key);
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	bool valid = false;
	int p = -1, i, j;
	for (i = 0; i < keyword.length(); i++)
	{
		for (j = i + 1; j < keyword.length(); j++)
		{
			if (keyword.at(i) == keyword.at(j))
			{
				p = i;
				break;
			}
		}
		if (p != -1)
		{
			break;
		}
	}

	if (p == -1)
	{
		valid = true;
	}

	return valid;
}

//incorrect
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

//incorrect
/*extern "C" EXPORT std::string checkValidityOfKeyword(char* key)
{
	char* keyword = key;
	if (checkCharactersInKeyword(key))
	{
		if (checkDuplicatesInKeyword(key))
		{
			keyword = key;
		}
		else
		{
			std::string(keyword) = removeDuplicates(key);
			if (checkLengthOfKeyword(&keyword[0]))
			{
				keyword = keyword;
			}
			else
			{
				keyword = "INVALID";
			}
		}
	}
	else
	{
		std::string(keyword) = "INVALID";
	}
	return std::string(keyword);
}*/

//correct
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

//correct
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


extern "C" EXPORT std::string encryptText(char** square, char* text, int width, int height)
{
	std::string textword(text);
	std::string encrypted, found;
	char letter;
	for (int i = 0; i < textword.length(); i++)
	{
		letter = textword.at(i);
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
		encrypted = found;
	}
	return encrypted;
}