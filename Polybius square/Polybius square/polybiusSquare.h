#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "constants.h"

class PolybiusSquare
{
private:
	std::string keyword;
	//char** polybiusSquare;
	
	char polybiusSquare [WIDTH][HEIGHT];

	//char* givenText;
	//char* encryptedText;


public:
	std::string getKeyword();

	bool checkCharactersInKeyword(std::string keyword);

	bool checkDuplicatesInKeyword(std::string keyword);



	bool checkValidityOfKeyword(std::string keyword);

	void setKeyword(std::string keyword);

	int createPolybiusSquare();

	std::string getText();

	bool checkValidityOfText(std::string text);

	std::string encryptText(std::string text);

	void showEncryptedText(std::string encryptedText);



	//robocze
	void showPolybiusSquare(char** polybiusSquare);


};
