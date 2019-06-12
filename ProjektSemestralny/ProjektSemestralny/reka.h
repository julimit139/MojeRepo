#pragma once
#include "stale.h"
#include "karta.h"
#include "talia.h"

class Reka
{
	std::vector<Karta> reka;			//wektor kart - rêka gracza
	Kolor kolorAtutowy;			//pole z kolorem atutowym 
public:
	Reka(Talia & talia);			//konstruktor obiektu klasy Reka
	void pobierzKarte(Talia & talia, int indeks);			//funkcja pobieraj¹ca kartê z talii/ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);			//funkcja pobieraj¹ca kartê spod indeksu - wersja do pierwszej czêœci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);			//funkcja pobieraj¹ca kartê spod indeksu - wersja do drugiej czêœci gry
	int znajdzIndeks(Karta karta);				//funkcja znajduj¹ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);			//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka w pierwszej czêœci gry 
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);				//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka w drugiej czêœci gry
	Karta & operator[](int indeks); //prze³adowany operator indeksowania, umo¿liwia dostanie siê do konkretnego elementu tablicy
	void wyswietlRekeKomputera1(sf::RenderWindow & window);
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);

	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);


	//void wyswietlAktualnaReke();			//funkcja wyœwietlaj¹ca aktualn¹ rêkê
	//void wyswietlAktualnaRekePomniejszona(int * tab);			//funkcja wyœwietlaj¹ca aktualn¹ pomniejszon¹ rêkê
	//int sprawdzWarunekPodmiany();				//funkcja sprawdzaj¹ca warunek podmiany dziewi¹tki w kolorze atutowym na kartê ze spodu stosu
	//void podmien(Talia & talia, int indeks);			//funkcja podmieniaj¹ca dziewi¹tkê atutow¹ na kartê ze spodu stosu
	//int sprawdzMeldunek();				//funkcja sprawdzaj¹ca, czy jest meldunek

};
