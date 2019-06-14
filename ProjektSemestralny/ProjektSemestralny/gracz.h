#pragma once

#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "lewa.h"

class Gracz
{
	Reka reka;								//rêka gracza
	Lewa * zbiorLew;						//zbiór lew zebranych przez gracza
	int licznikZebranychLew;				//pole z liczb¹ zebranych przez gracza lew
	int malePunkty = 0;						//pole z liczb¹ ma³ych punktów gracza
	
	//int duzePunkty;						//pole z liczb¹ du¿ych punktów gracza
public:
	Gracz(Talia & talia);																//konstruktor obiektu klasy Gracz
	void pobierzKarte(Talia & talia, int indeks);										//funkcja pobieraj¹ca kartê ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);											//funkcja pobieraj¹ca kartê spod indeksu - wersja dla pierwszej czêœci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);								//funkcja pobieraj¹ca kartê spod indeksu - wersja dla drugiej czêœci gry
	int znajdzIndeks(Karta karta);														//funkcja znajduj¹ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);											//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla pierwszej czêœci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);								//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla drugiej czêœci gry
	int dodajMalePunkty(int punkty);													//funkcja dodaj¹ca ma³e punkty
	int odczytajLiczbeMalychPunktow();													//funkcja odczytuj¹ca liczbê ma³ych punktów
	void dodajLewe(Karta karta1, Karta karta2);											//funkcja dodaj¹ca lewê do zbioru lew
	int wybierzKarte(sf::RenderWindow & window, int x, int y);							//funkcja 
	void wyswietlRekeKomputera1(sf::RenderWindow & window);								//funkcja wyœwietlaj¹ca rêkê komputera - wersja dla pierwszej czêœci gry	
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);								//funkcja wyœwietlaj¹ca rêkê cz³owieka - wersja dla pierwszej czêœci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);					//funkcja wyœwietlaj¹ca rêkê komputera - wersja dla drugiej czêœci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);					//funkcja wyœwietlaj¹ca rêkê cz³owieka - wersja dla drugiej czêœci gry
	Karta & wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks);		//funkcja wyœwietlaj¹ca kartê wy³o¿on¹ przez komputer
	Karta & wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks);		//funkcja wyœwietlaj¹ca kartê wy³o¿on¹ przez cz³owieka	
	void zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska);					//funkcja zakrywaj¹ca puste miejsce w rêce komputera
	void zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska);					//funkcja zakrywaj¹ca puste miejsce w rêce cz³owieka
	void zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska);		//funkcja zakrywaj¹ca kartê wy³o¿on¹ przez komputer
	void zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska);		//funkcja zakrywaj¹ca kartê wy³o¿on¹ przez cz³owieka
	void wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta karta);			//funkcja wyœwietlaj¹ca wygran¹ lewê komputera
	void wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta karta);			//funkcja wyœwietlaj¹ca wygran¹ lewê cz³owieka
	
	//Karta jakaKarta(int indeks);							//funkcja sprawdzaj¹ca, jaka karta jest pod podanym indeksem
	//int dodajDuzePunkty(int punkty);						//funkcja dodaj¹ca du¿e punkty
	//void wyswietlZbiorLew();								//funkcja wyœwietlaj¹ca zbiór lew
	//int sprawdz_warunek_podmiany(); //funkcja sprawdzaj¹ca warunek podmiany dziewi¹tki w kolorze atutowym na kartê ze spodu stosu
	//void podmien(Talia & talia, int indeks); //funkcja podmieniaj¹ca dziewi¹tkê atutow¹ na kartê ze spodu stosu
	//int sprawdz_meldunek(); //funkcja sprawdzaj¹ca, czy jest meldunek
};
