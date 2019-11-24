#include <iostream>
#include <process.h>
#include "polybiusSquare.h"

int main()
{
	PolybiusSquare mySquare;

	std::string key = mySquare.getKeyword();
	mySquare.setKeyword(key);
	
	mySquare.createPolybiusSquare();
	mySquare.setPolybiusSquare(mySquare.createPolybiusSquare());
	mySquare.showPolybiusSquare();

	std::string text = mySquare.getText();
	//std::string encryptedText= mySquare.encryptText(text);
	std::string encryptedText = mySquare.encryptTextDLLVersion(text, mySquare.getPolybiusSquare());
	mySquare.showEncryptedText(encryptedText);


	
	

	system("pause");
	return 0;
}