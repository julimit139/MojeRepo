#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "stale.h"
#include "karta.h"

class Talia
{
	std::vector<Karta> talia; 				//wektor kart - talia kart
public:
	Talia();			//konstruktor obiektu klasy Talia
	int tasujKarty();			//funkcja tasuj�ca tali� kart
	Karta zdejmijKarte();			//funkcja zdejmuj�ca kart� z talii/ze stosu
	Wartosc odczytajWartoscOdkrytejKartyAtutowej();				//funkcja odczytuj�ca warto�� karty okre�laj�cej kolor atutowy
	int odczytajDlugoscTalii();			//funkcja odczytuj�ca d�ugo�� talii/stosu
	Karta & pokazKarteAtutowa(); //DO KONTROLI


	Kolor odczytajKolorAtutowy();				//funkcja odczytuj�ca kolor atutowy
	void wypiszKolorAtutowy(Kolor kolorAtutowy);				//funkcja wypisuj�ca kolor atutowy									
	//void podmienKarteWTalii(Karta kartaDoPodmiany);			//funkcja podmieniaj�ca kart� ze spodu stosu na dziewi�tk� atutow�
	//void wyswietlTalie();			//funkcja wy�wietlaj�ca tali�
};