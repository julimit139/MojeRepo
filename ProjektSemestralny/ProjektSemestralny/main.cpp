#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"

int main()
{
	Talia talia;
	std::cout << talia.odczytajDlugoscTalii();
	
	talia.tasujKarty();
	
	getchar();
	return 0;
}