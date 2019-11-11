#include "polybiusSquare.h"

std::string PolybiusSquare::getKeyword()
{
	std::string keyword;
	std::cout << "Write a keyword with which your polybius square will be created:\n";
	std::cin >> keyword;
	return keyword;
}


bool PolybiusSquare::checkLengthOfkeyword(std::string keyword)
{
	bool valid = false;
	if (keyword.length() > 2 && keyword.length() < 8)
	{
		valid = true;
	}
	return valid;
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



/*std::string PolybiusSquare::removeDuplicate(std::string keyword)
{
	int index = 0;
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
	}
	return keyword;
}*/

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

char** PolybiusSquare::createPolybiusSquare()
{
	char** square = new char*[HEIGHT];
	for (int i = 0; i < HEIGHT; ++i)
	{
		square[i] = new char[WIDTH];
	}

	std::string newAlphabet = alphabet;
	for (int i = 0; i < keyword.length(); i++)
	{
		char letter = keyword.at(i);
		newAlphabet.erase(std::remove(newAlphabet.begin(), newAlphabet.end(), letter), newAlphabet.end());
	}

	newAlphabet = newAlphabet + specialSigns;

	//std::cout << newAlphabet << std::endl;
	//std::cout << newAlphabet.length() << std::endl;


	//writing spaces, numerals, letters and special signs to the table - in accordance with ASCII code
	square[0][0] = square[1][0] = 32; //writing spaces to the table

	
	for (int j = 1; j < (WIDTH - 1); j++)
	{
		square[0][j] = j + 48; //writing numerals to the table
	}
	square[0][10] = 48;

	for (int i = 2; i < HEIGHT; i++)
	{
		square[i][0] = keyword.length() - 1 + i + 48; //writing numerals to the table
		if ((keyword.length() == 7) && (i == 4))
		{
			square[i][0] = keyword.length() - 1 + i - 10 + 48;
		}
	}

	for (int j = 1; j < (keyword.length() + 1); j++)
	{
		square[1][j] = keyword.at(j-1); //writing keyword to the table
	}

	for (int j = (keyword.length() + 1); j < WIDTH; j++)
	{
		square[1][j] = 32; //writing spaces to the table
	}
	
	
	int iterator = 0;
	for (int i = 2; i < HEIGHT; i++)
	{
		if (i != 4)
		{
			for (int j = 1; j < WIDTH; j++)
			{
				square[i][j] = newAlphabet.at(iterator); //writing alphabet to the table
				iterator++;
			}
		}
		else
		{
			for (int j = 1; j < (WIDTH - keyword.length() + 1); j++)
			{
				square[i][j] = newAlphabet.at(iterator); //writing alphabet to the table
				iterator++;
			}
			for (int j = (WIDTH - keyword.length() + 1); j < WIDTH; j++)
			{
				square[i][j] = 32; //writing spaces to the table
			}
		}
	}

	return square;
}



void PolybiusSquare::setPolybiusSquare(char** polybiusSquare)
{
	this->polybiusSquare = polybiusSquare;
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

	std::cout << found << std::endl;

	return found;
}





/*std::string PolybiusSquare::encryptText(std::string text)
{
	std::string encrypted;
	char letter;
	for (int i = 0; i < text.length(); i++)
	{
		letter = text.at(i);
		




	}






	return encrypted;
}*/