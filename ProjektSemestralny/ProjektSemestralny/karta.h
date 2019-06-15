#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "stale.h"

class Karta
{
	Wartosc wartosc;				//pole z warto�ci� karty
	Kolor kolor;					//pole z kolorem karty
	std::string nazwaObrazu;		//pole z nazw� obrazu odpowiadaj�cego karcie

public:
	Karta();														//konstruktor domy�lny obiektu klasy Karta
	Karta(Wartosc w, Kolor k, std::string n);						//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();									//funkcja odczytuj�ca warto�� karty
	Kolor & odczytajKolor();										//funkcja odczytuj�ca kolor karty
	std::string odczytajNazweObrazu();								//funkcja odczytuj�ca nazw� obrazu odpowiadaj�cego karcie
	void zmienWlascowsciKarty(Karta nowa);							//funkcja zmieniaj�ca istniej�ce warto�ci p�l karty na nowe
	void wyswietlKarte(sf::RenderWindow & window, float x, float y);	//funkcja wy�wietlaj�ce kart� w oknie
};