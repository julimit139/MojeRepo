#include "polybiusSquare.h"

std::string PolybiusSquare::getKeyword()
{
	std::string keyword;
	std::cout << "Write a keyword with which your polybius square will be created:\n";
	std::cin >> keyword;
	return keyword;
}



bool PolybiusSquare::checkCharactersInKeyword(std::string keyword)
{
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	bool validKeyword = false, validCharacter = false;
	bool * validTable = new bool[keyword.length()];
	for (int i = 0; i < keyword.length(); i++)
	{
		validCharacter = false;
		for (int j = 0; j < ALPHABET; j++)
		{
			if (keyword.at(i) == alphabet[j])
			{
				validCharacter = true;
				validTable[i] = true;
				break;
			}
			else
			{
				validTable[i] = false;
			}
		}
	}

	for (int i = 0; i < keyword.length(); i++)
	{
		if (validTable[i] == true)
		{
			validKeyword = true;
		}
	}

	return validKeyword;
}



bool PolybiusSquare::checkValidityOfKeyword(std::string keyword)
{
	bool valid = false;
	if (keyword.length() >= 3 && keyword.length() <= 7)
	{

	}



	return valid;
}

void PolybiusSquare::setKeyword(std::string keyword)
{
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
	this->keyword = keyword;
}



std::string PolybiusSquare::getText()
{
	std::string text;
	std::cout << "Write text which you want to be encrypted:\n";
	std::cin >> text;
	return text;
}

void PolybiusSquare::showPolybiusSquare(char** polybiusSquare)
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




int PolybiusSquare::createPolybiusSquare()
{
	/*char * newAlphabet = new char[ALPHABET - keyword.length()];
	int counter = 0;
	for (int i = 0; i < (ALPHABET - keyword.length()); i++)
	{
		for (int j = 0; j < keyword.length(); j++)
		{
			if (alphabet[i] != keyword.at(j))
			{
				newAlphabet[counter] = alphabet[i];
				counter++;
				break;
			}

		}

	}*/


	std::string newAlphabet = alphabet;
	for (int i = 0; i < keyword.length(); i++)
	{
		char letter = keyword.at(i);
		newAlphabet.erase(std::remove(newAlphabet.begin(), newAlphabet.end(), letter), newAlphabet.end());
	}

	newAlphabet = newAlphabet + specialSigns;


	std::cout << newAlphabet << std::endl;
	std::cout << newAlphabet.length() << std::endl;


	polybiusSquare[0][0] = polybiusSquare[1][0] = '*';

	
	for (int j = 1; j < (WIDTH - 1); j++)
	{
		polybiusSquare[0][j] << char(j);
	}
	polybiusSquare[0][10] = '0';

	for (int i = 2; i < HEIGHT; i++)
	{
		polybiusSquare[i][0] = keyword.length() - 1 + i;
	}

	for (int j = 1; j < (keyword.length() + 1); j++)
	{
		polybiusSquare[1][j] << keyword.at(j-1);
	}

	for (int j = (keyword.length() + 1); j < WIDTH; j++)
	{
		polybiusSquare[1][j] = '*';
	}
	
	
	int iterator = 0;
	for (int i = 2; i < HEIGHT; i++)
	{
		if (i != 4)
		{
			for (int j = 1; j < WIDTH; j++)
			{
				polybiusSquare[i][j] = newAlphabet.at(iterator);
				iterator++;
			}
		}
		else
		{
			for (int j = 1; j < (WIDTH - keyword.length() + 1); j++)
			{
				polybiusSquare[i][j] = newAlphabet.at(iterator);
				iterator++;
			}
		}
		
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << polybiusSquare[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}