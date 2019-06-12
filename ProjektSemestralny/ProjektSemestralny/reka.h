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
	void pobierzKarte(Talia & talia, int indeks);			//funkcja pobieraj�ca kart� z talii/ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);			//funkcja pobieraj�ca kart� spod indeksu - wersja do pierwszej cz�ci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);			//funkcja pobieraj�ca kart� spod indeksu - wersja do drugiej cz�ci gry
	int znajdzIndeks(Karta karta);				//funkcja znajduj�ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);			//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w pierwszej cz�ci gry 
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);				//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w drugiej cz�ci gry
	Karta & operator[](int indeks); //prze�adowany operator indeksowania, umo�liwia dostanie si� do konkretnego elementu tablicy
	void wyswietlRekeKomputera1(sf::RenderWindow & window);
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);

	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);


	//void wyswietlAktualnaReke();			//funkcja wy�wietlaj�ca aktualn� r�k�
	//void wyswietlAktualnaRekePomniejszona(int * tab);			//funkcja wy�wietlaj�ca aktualn� pomniejszon� r�k�
	//int sprawdzWarunekPodmiany();				//funkcja sprawdzaj�ca warunek podmiany dziewi�tki w kolorze atutowym na kart� ze spodu stosu
	//void podmien(Talia & talia, int indeks);			//funkcja podmieniaj�ca dziewi�tk� atutow� na kart� ze spodu stosu
	//int sprawdzMeldunek();				//funkcja sprawdzaj�ca, czy jest meldunek

};
