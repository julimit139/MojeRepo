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
	std::vector<Karta> talia; 							//wektor kart tworz¹cy taliê kart
public:
	Talia();											//konstruktor obiektu klasy Talia
	int tasujKarty();									//funkcja tasuj¹ca taliê kart
	Karta zdejmijKarte();								//funkcja zdejmuj¹ca kartê z talii/ze stosu
	int odczytajDlugoscTalii();							//funkcja odczytuj¹ca d³ugoœæ talii/stosu
	Kolor odczytajKolorAtutowy();						//funkcja odczytuj¹ca kolor atutowy
	Wartosc odczytajWartoscOdkrytejKartyAtutowej();		//funkcja odczytuj¹ca wartoœæ karty okreœlaj¹cej kolor atutowy
	Karta & pokazKarteAtutowa();						//funkcja zwracaj¹ca kartê wyznaczaj¹c¹ kolor atutowy
};