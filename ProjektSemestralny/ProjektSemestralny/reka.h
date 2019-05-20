#pragma once
#include "stale.h"
#include "karta.h"
#include "talia.h"

class Reka
{
	std::vector<Karta> reka;			//wektor kart - r�ka gracza
	Kolor kolorAtutowy;			//pole z kolorem atutowym 
public:
	Reka(Talia & talia);			//konstruktor obiektu klasy Reka
	//Karta & operator[](int indeks);				//prze�adowany operator indeksowania, umo�liwia dostanie si� do konkretnego elementu tablicy
	//void pobierz_karte(Talia & talia, int indeks);			//funkcja pobieraj�ca kart� z talii/ze stosu
	//Karta & wez_karte_spod_indeksu_1(int indeks);			//funkcja pobieraj�ca kart� spod indeksu - wersja do pierwszej cz�ci gry
	//Karta & wez_karte_spod_indeksu_2(int indeks, int * tab);			//funkcja pobieraj�ca kart� spod indeksu - wersja do drugiej cz�ci gry
	//int znajdz_indeks(Karta karta);				//funkcja znajduj�ca indeks podanej karty
	//Karta dobierz_karte_1(Karta karta_wylozona);			//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w pierwszej cz�ci gry 
	//Karta dobierz_karte_2(Karta karta_wylozona, int * tab);				//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w drugiej cz�ci gry
	//void wyswietl_aktualna_reke();			//funkcja wy�wietlaj�ca aktualn� r�k�
	//void wyswietl_aktualna_reke_pomniejszona(int * tab);			//funkcja wy�wietlaj�ca aktualn� pomniejszon� r�k�
	//int sprawdz_warunek_podmiany();				//funkcja sprawdzaj�ca warunek podmiany dziewi�tki w kolorze atutowym na kart� ze spodu stosu
	//void podmien(Talia & talia, int indeks);			//funkcja podmieniaj�ca dziewi�tk� atutow� na kart� ze spodu stosu
	//int sprawdz_meldunek();				//funkcja sprawdzaj�ca, czy jest meldunek
};
