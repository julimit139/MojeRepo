#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"

int main()
{
	Talia talia;
	std::cout << talia.odczytajDlugoscTalii();

	talia.tasujKarty();

	talia.wyswietlTalie();
	std::cout << std::endl << std::endl;

	Reka mojaReka(talia);
	mojaReka.wyswietlAktualnaReke();
	std::cout << mojaReka.sprawdzWarunekPodmiany();
	std::cout << mojaReka.sprawdzMeldunek();
	

	getchar();
	return 0;
}