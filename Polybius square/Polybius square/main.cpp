#include <iostream>
#include <process.h>
#include "polybiusSquare.h"
#include <windows.h>

typedef std::string(__cdecl *f_funci)(std::string text, char** polybiusSquare, const int width, const int height);

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

	HINSTANCE hGetProcIDDLL = LoadLibrary("C:\\Users\\Julia\\source\\repos\\PolybiusSquareLibrary\\Debug\\PolybiusSquareLibrary.dll");

	if (!hGetProcIDDLL) {
		std::cout << "could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}

	// resolve function address here
	f_funci encryptTextDLLVersion = (f_funci)GetProcAddress(hGetProcIDDLL, "encryptTextDLLVersion");
	if (!encryptTextDLLVersion) {
		std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	std::string encryptedText = encryptTextDLLVersion(mySquare.enlargeLetters(text), mySquare.getPolybiusSquare(), width, height);
	mySquare.showEncryptedText(encryptedText);

	
	
	

	system("pause");
	return 0;
}