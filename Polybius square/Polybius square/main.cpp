#include <iostream>
#include <process.h>
#include "polybiusSquare.h"

int main()
{
	PolybiusSquare mySquare;

	std::string key = mySquare.getKeyword();
	
	//mySquare.removeDuplicate(key);
	
	mySquare.setKeyword(key);
	mySquare.createPolybiusSquare();
	mySquare.setPolybiusSquare(mySquare.createPolybiusSquare());
	mySquare.showPolybiusSquare();

	mySquare.findLetter('A');
	

	system("pause");
	return 0;
}