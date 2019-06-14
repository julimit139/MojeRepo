#pragma once
#include "stale.h"
#include "karta.h"
#include "talia.h"

class Reka
{
	std::vector<Karta> reka;				//wektor kart tworz�cy r�k� gracza
	Kolor kolorAtutowy;						//pole z kolorem atutowym 
public:
	Reka(Talia & talia);													//konstruktor obiektu klasy Reka
	void pobierzKarte(Talia & talia, int indeks);							//funkcja pobieraj�ca kart� z talii/ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);								//funkcja pobieraj�ca kart� spod indeksu - wersja dla pierwszej cz�ci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);					//funkcja pobieraj�ca kart� spod indeksu - wersja dla drugiej cz�ci gry
	int znajdzIndeks(Karta karta);											//funkcja znajduj�ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);								//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla pierwszej cz�ci gry 
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);					//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla drugiej cz�ci gry
	Karta & operator[](int indeks);											//prze�adowany operator indeksowania umo�liwiaj�cy dostanie si� do konkretnego elementu wektora
	void wyswietlRekeKomputera1(sf::RenderWindow & window);					//funkcja wy�wietlaj�ca r�k� komputera w oknie - wersja dla pierwszej cz�ci gry
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);					//funkcja wy�wietlaj�ca r�k� cz�owieka w oknie - wersja dla pierwszej cz�ci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);		//funkcja wy�wietlaj�ca r�k� komputera w oknie - wersja dla drugiej cz�ci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);		//funkcja wy�wietlaj�ca r�k� cz�owieka w oknie - wersja dla drugiej cz�ci gry

	//int sprawdzWarunekPodmiany();				//funkcja sprawdzaj�ca warunek podmiany dziewi�tki w kolorze atutowym na kart� ze spodu stosu
	//void podmien(Talia & talia, int indeks);			//funkcja podmieniaj�ca dziewi�tk� atutow� na kart� ze spodu stosu
	//int sprawdzMeldunek();				//funkcja sprawdzaj�ca, czy jest meldunek
};
