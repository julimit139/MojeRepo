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
	int tasujKarty();			//funkcja tasuj¹ca taliê kart
	Karta zdejmijKarte();			//funkcja zdejmuj¹ca kartê z talii/ze stosu
	Kolor odczytajKolorAtutowy();				//funkcja odczytuj¹ca kolor atutowy
	/*void wypisz_kolor_atutowy(Kolor kolor_atutowy);				//funkcja wypisuj¹ca kolor atutowy
	Wartosc odczytaj_wartosc_odkrytej_karty_atutowej();*/				//funkcja odczytuj¹ca wartoœæ karty okreœlaj¹cej kolor atutowy
	int odczytajDlugoscTalii();			//funkcja odczytuj¹ca d³ugoœæ talii/stosu
	//void podmien_karte_w_talii(Karta karta_do_podmiany);			//funkcja podmieniaj¹ca kartê ze spodu stosu na dziewi¹tkê atutow¹
	void wyswietlTalie();			//funkcja wyœwietlaj¹ca taliê
};