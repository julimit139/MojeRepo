#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "constants.h"

class PolybiusSquare
{
private:
	std::string keyword;
	char** polybiusSquare;
	
	//char polybiusSquare [WIDTH][HEIGHT];

	//char* givenText;
	//char* encryptedText;


public:

	//done
	std::string getKeyword(); 

	//done
	bool checkLengthOfkeyword(std::string keyword);

	//done
	bool checkCharactersInKeyword(std::string keyword);


	//bool checkDuplicatesInKeyword(std::string keyword);


	//std::string removeDuplicate(std::string keyword);
	



	bool checkValidityOfKeyword(std::string keyword);

	//done
	void setKeyword(std::string keyword);

	//done
	char** createPolybiusSquare();

	//done
	void setPolybiusSquare(char** polybiusSquare);

	//done
	std::string getText();


	bool checkValidityOfText(std::string text);


	std::string findLetter(char letter);


	std::string encryptText(std::string text);

	void showEncryptedText(std::string encryptedText);



	//robocze
	//done
	void showPolybiusSquare();


};
