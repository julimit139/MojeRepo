#pragma once

#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "lewa.h"

class Gracz
{
	Reka reka;								//r�ka gracza
	Lewa * zbiorLew;						//zbi�r lew zebranych przez gracza
	int licznikZebranychLew = 0;			//pole z liczb� zebranych przez gracza lew
	int liczbaPunktow = 0;							//pole z liczb� ma�ych punkt�w gracza
public:
	Gracz(Talia & talia);																//konstruktor obiektu klasy Gracz
	void pobierzKarte(Talia & talia, int indeks);										//funkcja pobieraj�ca kart� ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);											//funkcja pobieraj�ca kart� spod indeksu - wersja dla pierwszej cz�ci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);								//funkcja pobieraj�ca kart� spod indeksu - wersja dla drugiej cz�ci gry
	int znajdzIndeks(Karta karta);														//funkcja znajduj�ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);											//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla pierwszej cz�ci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);								//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla drugiej cz�ci gry
	int dodajPunkty(int punkty);													//funkcja dodaj�ca ma�e punkty
	int odczytajLiczbePunktow();													//funkcja odczytuj�ca liczb� ma�ych punkt�w
	void dodajLewe(Karta kartaKomputeta, Karta kartaCzlowieka);											//funkcja dodaj�ca lew� do zbioru lew
	int wybierzKarte(sf::RenderWindow & window, int x, int y, const float X[6], const float Y[2], const float w, const float s);							//funkcja 
	void wyswietlRekeKomputera1(sf::RenderWindow & window, const float x[6], const float y[2]);								//funkcja wy�wietlaj�ca r�k� komputera - wersja dla pierwszej cz�ci gry	
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window, const float x[6], const float y[2]);								//funkcja wy�wietlaj�ca r�k� cz�owieka - wersja dla pierwszej cz�ci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2]);					//funkcja wy�wietlaj�ca r�k� komputera - wersja dla drugiej cz�ci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2]);					//funkcja wy�wietlaj�ca r�k� cz�owieka - wersja dla drugiej cz�ci gry
	Karta & wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks, const float x, const float y);		//funkcja wy�wietlaj�ca kart� wy�o�on� przez komputer
	Karta & wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks, const float x, const float y);		//funkcja wy�wietlaj�ca kart� wy�o�on� przez cz�owieka	
	void zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska);					//funkcja zakrywaj�ca puste miejsce w r�ce komputera
	void zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska);					//funkcja zakrywaj�ca puste miejsce w r�ce cz�owieka
	void zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska);		//funkcja zakrywaj�ca kart� wy�o�on� przez komputer
	void zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska);		//funkcja zakrywaj�ca kart� wy�o�on� przez cz�owieka
	void wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta kartaKomputera, const float x, const float y[2]);			//funkcja wy�wietlaj�ca wygran� lew� komputera
	void wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta kartaCzlowieka, const float x, const float y[2]);			//funkcja wy�wietlaj�ca wygran� lew� cz�owieka
};
