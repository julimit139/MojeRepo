#pragma once

#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "lewa.h"

class Gracz
{
	Reka reka;			 //rêka gracza
	Lewa * zbiorLew;			//zbiór lew zebranych przez gracza
	int licznikZebranychLew;			//pole z liczb¹ zebranych przez gracza lew
	int malePunkty;			//pole z liczb¹ ma³ych punktów gracza
	int duzePunkty;			//pole z liczb¹ du¿ych punktów gracza
public:
	Gracz(Talia & talia); //konstruktor obiektu klasy Gracz
	Karta & wezKarteSpodIndeksu1(int indeks); //funkcja pobieraj¹ca kartê spod indeksu - wersja do pierwszej czêœci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab); //funkcja pobieraj¹ca kartê spod indeksu - wersja do drugiej czêœci gry
	int znajdzIndeks(Karta karta); //funkcja znajduj¹ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona); //funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka w pierwszej czêœci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab); //funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka w drugiej czêœci gry
	int dodajDuzePunkty(int punkty); //funkcja dodaj¹ca du¿e punkty
	int dodajMalePunkty(int punkty); //funkcja dodaj¹ca ma³e punkty
	int odczytajLiczbeMalychPunktow(); //funkcja odczytuj¹ca liczbê ma³ych punktów
	Karta jakaKarta(int indeks); //funkcja sprawdzaj¹ca, jaka karta jest pod podanym indeksem
	void dodajLewe(Karta karta1, Karta karta2); //funkcja dodaj¹ca lewê do zbioru lew
	void wyswietlZbiorLew(); //funkcja wyœwietlaj¹ca zbiór lew
	
	
	int wybierzKarte(sf::RenderWindow & window, int x, int y);

	void wyswietlRekeCzlowieka(sf::RenderWindow & window);
	void wyswietlRekeKomputera(sf::RenderWindow & window);
	
	Karta & wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks);
	Karta & wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks);
	void wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta karta);
	void wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta karta);

	void zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const int tabX[6]);
	void zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const int tabX[6]);


	//void pobierzKarte(sf::RenderWindow & window, int x, int y, Talia & talia, int indeks);
	//void wyswietl_reke(); //funkcja wyœwietlaj¹ca aktualn¹ rêkê
	//void wyswietl_reke_pomniejszona(int * tab); //funkcja wyœwietlaj¹ca aktualn¹ pomniejszon¹ rêkê
	//int sprawdz_warunek_podmiany(); //funkcja sprawdzaj¹ca warunek podmiany dziewi¹tki w kolorze atutowym na kartê ze spodu stosu
	//void podmien(Talia & talia, int indeks); //funkcja podmieniaj¹ca dziewi¹tkê atutow¹ na kartê ze spodu stosu
	//int sprawdz_meldunek(); //funkcja sprawdzaj¹ca, czy jest meldunek
	//void pobierzKarte(Talia & talia, int indeks); //funkcja pobieraj¹ca kartê ze stosu

};
