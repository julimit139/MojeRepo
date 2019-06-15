#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "stale.h"

class Karta
{
	Wartosc wartosc;				//pole z wartoœci¹ karty
	Kolor kolor;					//pole z kolorem karty
	std::string nazwaObrazu;		//pole z nazw¹ obrazu odpowiadaj¹cego karcie

public:
	Karta();														//konstruktor domyœlny obiektu klasy Karta
	Karta(Wartosc w, Kolor k, std::string n);						//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();									//funkcja odczytuj¹ca wartoœæ karty
	Kolor & odczytajKolor();										//funkcja odczytuj¹ca kolor karty
	std::string odczytajNazweObrazu();								//funkcja odczytuj¹ca nazwê obrazu odpowiadaj¹cego karcie
	void zmienWlascowsciKarty(Karta nowa);							//funkcja zmieniaj¹ca istniej¹ce wartoœci pól karty na nowe
	void wyswietlKarte(sf::RenderWindow & window, float x, float y);	//funkcja wyœwietlaj¹ce kartê w oknie
};