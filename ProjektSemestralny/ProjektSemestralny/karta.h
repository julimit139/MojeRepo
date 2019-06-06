#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "stale.h"

class Karta
{
public:
	Wartosc wartosc;			//pole z wartoœci¹ karty
	Kolor kolor;			//pole z kolorem karty
	std::string nazwaObrazu;


	Karta();			//konstruktor domyœlny obiektu klasy Karta
	Karta(Wartosc w, Kolor k, std::string n);				//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();			//funkcja odczytuj¹ca wartoœæ karty
	Kolor & odczytajKolor();			//funkcja odczytuj¹ca kolor karty
	std::string odczytajNazweObrazu();
	void wyswietlKarte(sf::RenderWindow & window, int x, int y);

	friend std::ostream & operator << (std::ostream & wypisz, Karta karta);			//zaprzyjaŸniona funkcja wypisuj¹ca kartê na ekran
};

std::ostream & operator << (std::ostream & wypisz, Karta karta);			//funkcja wypisuj¹ca kartê na ekran