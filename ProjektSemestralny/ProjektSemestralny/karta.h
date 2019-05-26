#pragma once
#include <iostream>
#include "stale.h"

class Karta
{
	Wartosc wartosc;			//pole z wartoœci¹ karty
	Kolor kolor;			//pole z kolorem karty
public:
	Karta();			//konstruktor domyœlny obiektu klasy Karta
	Karta(Wartosc w, Kolor k);				//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();			//funkcja odczytuj¹ca wartoœæ karty
	Kolor & odczytajKolor();			//funkcja odczytuj¹ca kolor karty
	friend std::ostream & operator << (std::ostream & wypisz, Karta karta);			//zaprzyjaŸniona funkcja wypisuj¹ca kartê na ekran
};

std::ostream & operator << (std::ostream & wypisz, Karta karta);			//funkcja wypisuj¹ca kartê na ekran