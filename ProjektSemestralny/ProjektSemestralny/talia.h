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
	Kolor odczytajKolorAtutowy();				//funkcja odczytuj�ca kolor atutowy
	/*void wypisz_kolor_atutowy(Kolor kolor_atutowy);				//funkcja wypisuj�ca kolor atutowy
	Wartosc odczytaj_wartosc_odkrytej_karty_atutowej();*/				//funkcja odczytuj�ca warto�� karty okre�laj�cej kolor atutowy
	int odczytajDlugoscTalii();			//funkcja odczytuj�ca d�ugo�� talii/stosu
	//void podmien_karte_w_talii(Karta karta_do_podmiany);			//funkcja podmieniaj�ca kart� ze spodu stosu na dziewi�tk� atutow�
	void wyswietlTalie();			//funkcja wy�wietlaj�ca tali�
};