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
	std::vector<Karta> talia; 							//wektor kart tworz�cy tali� kart
public:
	Talia();											//konstruktor obiektu klasy Talia
	int tasujKarty();									//funkcja tasuj�ca tali� kart
	Karta zdejmijKarte();								//funkcja zdejmuj�ca kart� z talii/ze stosu
	int odczytajDlugoscTalii();							//funkcja odczytuj�ca d�ugo�� talii/stosu
	Kolor odczytajKolorAtutowy();						//funkcja odczytuj�ca kolor atutowy
	Wartosc odczytajWartoscOdkrytejKartyAtutowej();		//funkcja odczytuj�ca warto�� karty okre�laj�cej kolor atutowy
	Karta & pokazKarteAtutowa();						//funkcja zwracaj�ca kart� wyznaczaj�c� kolor atutowy
};