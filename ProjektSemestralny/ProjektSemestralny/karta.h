#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "stale.h"

class Karta
{
	Wartosc wartosc;				//pole z wartością karty
	Kolor kolor;					//pole z kolorem karty
	std::string nazwaObrazu;		//pole z nazwą obrazu odpowiadającego karcie

public:
	Karta();															//konstruktor domyślny obiektu klasy Karta
	Karta(Wartosc w, Kolor k, std::string n);							//konstruktor obiektu klasy Karta
	Wartosc & odczytajWartosc();										//funkcja odczytująca wartość karty
	Kolor & odczytajKolor();											//funkcja odczytująca kolor karty
	std::string odczytajNazweObrazu();									//funkcja odczytująca nazwę obrazu odpowiadającego karcie
	void zmienWlasciwosciKarty(Karta nowa);								//funkcja zmieniająca istniejące wartości pól karty na nowe
	void wyswietlKarte(sf::RenderWindow & window, float x, float y);	//funkcja wyświetlające kartę w oknie
};