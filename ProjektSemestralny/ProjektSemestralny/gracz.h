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
	int licznikZebranychLew = 0;			//pole z liczb¹ zebranych przez gracza lew
	int liczbaPunktow = 0;							//pole z liczb¹ ma³ych punktów gracza
public:
	Gracz(Talia & talia);																//konstruktor obiektu klasy Gracz
	void pobierzKarte(Talia & talia, int indeks);										//funkcja pobieraj¹ca kartê ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);											//funkcja pobieraj¹ca kartê spod indeksu - wersja dla pierwszej czêœci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);								//funkcja pobieraj¹ca kartê spod indeksu - wersja dla drugiej czêœci gry
	int znajdzIndeks(Karta karta);														//funkcja znajduj¹ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);											//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla pierwszej czêœci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);								//funkcja dobieraj¹ca kartê do wy³o¿onej przez cz³owieka dla drugiej czêœci gry
	int dodajPunkty(int punkty);													//funkcja dodaj¹ca ma³e punkty
	int odczytajLiczbePunktow();													//funkcja odczytuj¹ca liczbê ma³ych punktów
	void dodajLewe(Karta kartaKomputeta, Karta kartaCzlowieka);											//funkcja dodaj¹ca lewê do zbioru lew
	int wybierzKarte(sf::RenderWindow & window, int x, int y, const float X[6], const float Y[2], const float w, const float s);							//funkcja 
	void wyswietlRekeKomputera1(sf::RenderWindow & window, const float x[6], const float y[2]);								//funkcja wyœwietlaj¹ca rêkê komputera - wersja dla pierwszej czêœci gry	
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window, const float x[6], const float y[2]);								//funkcja wyœwietlaj¹ca rêkê cz³owieka - wersja dla pierwszej czêœci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2]);					//funkcja wyœwietlaj¹ca rêkê komputera - wersja dla drugiej czêœci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2]);					//funkcja wyœwietlaj¹ca rêkê cz³owieka - wersja dla drugiej czêœci gry
	Karta & wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks, const float x, const float y);		//funkcja wyœwietlaj¹ca kartê wy³o¿on¹ przez komputer
	Karta & wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks, const float x, const float y);		//funkcja wyœwietlaj¹ca kartê wy³o¿on¹ przez cz³owieka	
	void zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska);					//funkcja zakrywaj¹ca puste miejsce w rêce komputera
	void zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska);					//funkcja zakrywaj¹ca puste miejsce w rêce cz³owieka
	void zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska);		//funkcja zakrywaj¹ca kartê wy³o¿on¹ przez komputer
	void zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska);		//funkcja zakrywaj¹ca kartê wy³o¿on¹ przez cz³owieka
	void wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta kartaKomputera, const float x, const float y[2]);			//funkcja wyœwietlaj¹ca wygran¹ lewê komputera
	void wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta kartaCzlowieka, const float x, const float y[2]);			//funkcja wyœwietlaj¹ca wygran¹ lewê cz³owieka
};
