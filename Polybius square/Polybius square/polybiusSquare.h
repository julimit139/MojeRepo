#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "constants.h"

class PolybiusSquare
{
private:
	std::string keyword; //field containing keyword given by user
	char** polybiusSquare; //two-dimensional array containing Polybius square
	


public:

	std::string getKeyword(); //gets keyword from user

	bool checkLengthOfkeyword(std::string keyword); //checks whether the length of given keyword is in specific range

	
	bool checkCharactersInKeyword(std::string keyword); //checks whether letters forming given keyword belong to english alphabet


	bool checkDuplicatesInKeyword(std::string keyword); //checks whether given keyword contains duplicated letters

	//to improve, something connected with indexes doesn't work
	std::string removeDuplicate(std::string keyword); //removes duplicated letters from given keyword
	


	//bool checkValidityOfKeyword(std::string keyword); //checks validity of given keyword




	void setKeyword(std::string keyword); //sets keyword

	
	char** createPolybiusSquare(); //creates Polybius square based on keyword


	void setPolybiusSquare(char** polybiusSquare); //sets Polybius square

	
	std::string getText(); //gets text from user


	bool checkValidityOfText(std::string text); //checks validity of given text

	

	std::string findLetter(char letter); //finds letter in Polybius square

	
	std::string encryptText(std::string text); //encrypts given text


	void showEncryptedText(std::string encryptedText); //shows encrypted text



	//robocze
	//done
	void showPolybiusSquare(); //shows Polybius square


};
