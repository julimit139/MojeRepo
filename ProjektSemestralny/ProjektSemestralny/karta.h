#pragma once
#include <iostream>
#include "stale.h"

class Karta
{
	Wartosc wartosc;			//pole z warto�ci� karty
	Kolor kolor;			//pole z kolorem karty
public:
	Karta();			//konstruktor domy�lny obiektu klasy Karta
	Karta(Wartosc w, Kolor k);				//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();			//funkcja odczytuj�ca warto�� karty
	Kolor & odczytajKolor();			//funkcja odczytuj�ca kolor karty
	friend std::ostream & operator << (std::ostream & wypisz, Karta karta);			//zaprzyja�niona funkcja wypisuj�ca kart� na ekran
};

std::ostream & operator << (std::ostream & wypisz, Karta karta);			//funkcja wypisuj�ca kart� na ekran