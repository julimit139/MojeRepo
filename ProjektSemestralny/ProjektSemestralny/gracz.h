#pragma once

#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "lewa.h"

class Gracz
{
	Reka reka;			 //r�ka gracza
	Lewa * zbiorLew;			//zbi�r lew zebranych przez gracza
	int licznikZebranychLew;			//pole z liczb� zebranych przez gracza lew
	int malePunkty;			//pole z liczb� ma�ych punkt�w gracza
	int duzePunkty;			//pole z liczb� du�ych punkt�w gracza
public:
	Gracz(Talia & talia); //konstruktor obiektu klasy Gracz
	Karta & wezKarteSpodIndeksu1(int indeks); //funkcja pobieraj�ca kart� spod indeksu - wersja do pierwszej cz�ci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab); //funkcja pobieraj�ca kart� spod indeksu - wersja do drugiej cz�ci gry
	int znajdzIndeks(Karta karta); //funkcja znajduj�ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona); //funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w pierwszej cz�ci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab); //funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka w drugiej cz�ci gry
	int dodajDuzePunkty(int punkty); //funkcja dodaj�ca du�e punkty
	int dodajMalePunkty(int punkty); //funkcja dodaj�ca ma�e punkty
	int odczytajLiczbeMalychPunktow(); //funkcja odczytuj�ca liczb� ma�ych punkt�w
	Karta jakaKarta(int indeks); //funkcja sprawdzaj�ca, jaka karta jest pod podanym indeksem
	void dodajLewe(Karta karta1, Karta karta2); //funkcja dodaj�ca lew� do zbioru lew
	void wyswietlZbiorLew(); //funkcja wy�wietlaj�ca zbi�r lew
	
	
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
	//void wyswietl_reke(); //funkcja wy�wietlaj�ca aktualn� r�k�
	//void wyswietl_reke_pomniejszona(int * tab); //funkcja wy�wietlaj�ca aktualn� pomniejszon� r�k�
	//int sprawdz_warunek_podmiany(); //funkcja sprawdzaj�ca warunek podmiany dziewi�tki w kolorze atutowym na kart� ze spodu stosu
	//void podmien(Talia & talia, int indeks); //funkcja podmieniaj�ca dziewi�tk� atutow� na kart� ze spodu stosu
	//int sprawdz_meldunek(); //funkcja sprawdzaj�ca, czy jest meldunek
	//void pobierzKarte(Talia & talia, int indeks); //funkcja pobieraj�ca kart� ze stosu

};
