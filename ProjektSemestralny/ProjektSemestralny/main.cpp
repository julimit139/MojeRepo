#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"

int main()
{
	Talia talia;
	std::cout << talia.odczytajDlugoscTalii();

	talia.tasujKarty();

	talia.wyswietlTalie();
	std::cout << std::endl << std::endl;
	std::cout << talia.zdejmijKarte() << std::endl;
	std::cout << std::endl << std::endl;
	talia.wyswietlTalie();

	talia.odczytajKolorAtutowy();



	getchar();
	return 0;
}