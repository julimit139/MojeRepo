#include <iostream>
#include <process.h>
#include "polybiusSquare.h"

int main()
{
	PolybiusSquare mySquare;

	std::string key = mySquare.getKeyword();
	mySquare.setKeyword(key);
	mySquare.createPolybiusSquare();
	

	system("pause");
	return 0;
}