#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "stale.h"

class Karta
{
public:
	Wartosc wartosc;			//pole z warto�ci� karty
	Kolor kolor;			//pole z kolorem karty
	std::string nazwaObrazu;


	Karta();			//konstruktor domy�lny obiektu klasy Karta
	Karta(Wartosc w, Kolor k, std::string n);				//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();			//funkcja odczytuj�ca warto�� karty
	Kolor & odczytajKolor();			//funkcja odczytuj�ca kolor karty
	std::string odczytajNazweObrazu();
	void wyswietlKarte(sf::RenderWindow & window, int x, int y);

	friend std::ostream & operator << (std::ostream & wypisz, Karta karta);			//zaprzyja�niona funkcja wypisuj�ca kart� na ekran
};

std::ostream & operator << (std::ostream & wypisz, Karta karta);			//funkcja wypisuj�ca kart� na ekran