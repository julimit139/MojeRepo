#include "polybiusSquare.h"

std::string PolybiusSquare::getKeyword()
{
	std::string keyword;
	std::cout << "Enter the keyword on which your Polybius square will be based:\n";
	std::cin >> keyword;
	return keyword;
}


bool PolybiusSquare::checkLengthOfkeyword(std::string keyword)
{
	bool valid = false;
	if ((keyword.length() > 2) && (keyword.length() < 8))
	{
		valid = true;
	}
	return valid;
}


bool PolybiusSquare::checkCharactersInKeyword(std::string keyword)
{
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

bool PolybiusSquare::checkDuplicatesInKeyword(std::string keyword)
{
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



std::string PolybiusSquare::removeDuplicate(std::string keyword)
{
	std::string key = keyword;
	for (int i = 0; i < key.length(); i++)
	{
		for (int j = i + 1; j < key.length(); j++)
		{
			if (key.at(i) == key.at(j))
			{
				key.erase(key.begin() + j);
			}
		}
	}



	/*int index = 0;
	for (int i = 0; i < keyword.length(); i++) 
	{
		char currentLetter = keyword.at(i);
		for (int j = i + 1; j < keyword.length(); j++)
		{
			{
			if (currentLetter == keyword.at(j))
				keyword.erase(std::remove(keyword.begin() + j, keyword.end(), keyword.at(j), keyword.end());
			}
			if (keyword.at(i) == keyword.at(j))
			{
				break;
			}
				
		}	
		if (j == i)
		{
			keyword.at(index++) = keyword.at(i);
		}			
	}*/

	return key;
}

/*bool PolybiusSquare::checkValidityOfKeyword(std::string keyword)
{
	bool valid = false;
	if (checkLengthOfkeyword(keyword))
	{
		if (checkCharactersInKeyword(keyword))
		{
			if (checkDuplicatesInKeyword(keyword))
			{
				valid = true;
			}
		}
	}



	return valid;
}*/




void PolybiusSquare::setKeyword(std::string keyword)
{
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper); //transformation of keyword's letters to upper case
	this->keyword = keyword;
}


char** PolybiusSquare::createPolybiusSquare()
{
	char** square = new char*[HEIGHT]; //declaration of two-dimensional array 
	for (int i = 0; i < HEIGHT; ++i)
	{
		square[i] = new char[WIDTH];
	}

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
		square[1][j] = keyword.at(j-1); //writing keyword to the array
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
	return square;
}



void PolybiusSquare::setPolybiusSquare(char** polybiusSquare)
{
	this->polybiusSquare = polybiusSquare;
}


std::string PolybiusSquare::getText()
{
	std::string text;
	std::cout << "Enter the text you would like it to be encrypted:\n";
	std::getline(std::cin >> std::ws, text);
	return text;
}



std::string PolybiusSquare::findLetter(char letter)
{
	std::string found;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (polybiusSquare[i][j] == letter)
			{
				if (i != 1)
				{
					found += std::to_string(polybiusSquare[i][0] - 48);
				}
				found += std::to_string(polybiusSquare[0][j] - 48);
				break;
			}
		}
	}
	return found;
}


std::string PolybiusSquare::encryptText(std::string text)
{
	std::string encrypted, found;
	char letter;
	for (int i = 0; i < text.length(); i++)
	{
		letter = text.at(i);
		found = findLetter(letter);
		encrypted += found;
	}
	return encrypted;
}


void PolybiusSquare::showEncryptedText(std::string encryptedText)
{
	std::cout << encryptedText << std::endl;
}




void PolybiusSquare::showPolybiusSquare()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << polybiusSquare[i][j] << " ";
		}
		std::cout << "\n";
	}
}