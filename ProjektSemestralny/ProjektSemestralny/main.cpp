#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"

int main()
{
	//foo();
	Talia talia;
	talia.tasujKarty();
	std::cout << std::endl << std::endl;

	Reka mojaReka(talia);
	mojaReka.wyswietlAktualnaReke();
	//std::cout << mojaReka.sprawdzWarunekPodmiany();
	//std::cout << mojaReka.sprawdzMeldunek();


	sf::RenderWindow window(sf::VideoMode(1200, 650), "My window", sf::Style::Default);

	//Karta k(dama, pik, "dama_pik.jpg");
	//k.wyswietlKarte(window);
	//mojaReka[0].wyswietlKarte(window);
	
	//mojaReka.wyswietlRekeKomputera(window);
	mojaReka.wyswietlRekeCzlowieka(window);


	return 0;
	getchar();
}