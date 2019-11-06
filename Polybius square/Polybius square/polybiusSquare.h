#pragma once
#include <iostream>
#include <string>

class PolybiusSquare
{
private:
	std::string keyWord;
	char** polybiusSquare;
	char* givenText;
	char* encryptedText;


public:
	std::string getKeyWord();

	bool checkValidityOfKeyWord(std::string keyWord);

	void setKeyWord();

	int createPolybiusSquare(std::string keyWord);

	std::string getText();

	bool checkValidityOfText(std::string text);

	int encryptText(std::string text);

	void showEncryptedText(int encryptedText[]);



};
