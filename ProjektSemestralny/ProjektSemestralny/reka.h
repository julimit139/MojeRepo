#pragma once
#include "stale.h"
#include "karta.h"
#include "talia.h"

class Reka
{
	std::vector<Karta> reka;				//wektor kart tworz¹cy rêkê gracza
	Kolor kolorAtutowy;						//pole z kolorem atutowym 
public:
	Reka(Talia & talia);													//konstruktor obiektu klasy Reka
	void pobierzKarte(Talia & talia, int indeks);							//funkcja pobieraj¹ca kartê z talii/ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);								//funkcja pobieraj¹ca kartê spod indeksu - wersja dla pierwszej czêœci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);					//funkcja pobieraj¹ca kartê spod indeksu - wersja dla drugiej czêœci gry
	int znajdzIndeks(Karta karta);											//funkcja znajduj¹ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);								//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla pierwszej czêœci gry 
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);					//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla drugiej czêœci gry
	Karta & operator[](int indeks);											//prze³adowany operator indeksowania umo¿liwiaj¹cy dostanie siê do konkretnego elementu wektora
	void wyswietlRekeKomputera1(sf::RenderWindow & window);					//funkcja wyœwietlaj¹ca rêkê komputera w oknie - wersja dla pierwszej czêœci gry
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);					//funkcja wyœwietlaj¹ca rêkê cz³owieka w oknie - wersja dla pierwszej czêœci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);		//funkcja wyœwietlaj¹ca rêkê komputera w oknie - wersja dla drugiej czêœci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);		//funkcja wyœwietlaj¹ca rêkê cz³owieka w oknie - wersja dla drugiej czêœci gry

	//int sprawdzWarunekPodmiany();				//funkcja sprawdzaj¹ca warunek podmiany dziewi¹tki w kolorze atutowym na kartê ze spodu stosu
	//void podmien(Talia & talia, int indeks);			//funkcja podmieniaj¹ca dziewi¹tkê atutow¹ na kartê ze spodu stosu
	//int sprawdzMeldunek();				//funkcja sprawdzaj¹ca, czy jest meldunek
};
