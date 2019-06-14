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
	int licznikZebranychLew;				//pole z liczb� zebranych przez gracza lew
	int malePunkty = 0;						//pole z liczb� ma�ych punkt�w gracza
	
	//int duzePunkty;						//pole z liczb� du�ych punkt�w gracza
public:
	Gracz(Talia & talia);																//konstruktor obiektu klasy Gracz
	void pobierzKarte(Talia & talia, int indeks);										//funkcja pobieraj�ca kart� ze stosu
	Karta & wezKarteSpodIndeksu1(int indeks);											//funkcja pobieraj�ca kart� spod indeksu - wersja dla pierwszej cz�ci gry
	Karta & wezKarteSpodIndeksu2(int indeks, int * tab);								//funkcja pobieraj�ca kart� spod indeksu - wersja dla drugiej cz�ci gry
	int znajdzIndeks(Karta karta);														//funkcja znajduj�ca indeks podanej karty
	Karta dobierzKarte1(Karta kartaWylozona);											//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla pierwszej cz�ci gry
	Karta dobierzKarte2(Karta kartaWylozona, int * tab);								//funkcja dobieraj�ca kart� do wy�o�onej przez cz�owieka dla drugiej cz�ci gry
	int dodajMalePunkty(int punkty);													//funkcja dodaj�ca ma�e punkty
	int odczytajLiczbeMalychPunktow();													//funkcja odczytuj�ca liczb� ma�ych punkt�w
	void dodajLewe(Karta karta1, Karta karta2);											//funkcja dodaj�ca lew� do zbioru lew
	int wybierzKarte(sf::RenderWindow & window, int x, int y);							//funkcja 
	void wyswietlRekeKomputera1(sf::RenderWindow & window);								//funkcja wy�wietlaj�ca r�k� komputera - wersja dla pierwszej cz�ci gry	
	void wyswietlRekeCzlowieka1(sf::RenderWindow & window);								//funkcja wy�wietlaj�ca r�k� cz�owieka - wersja dla pierwszej cz�ci gry
	void wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6]);					//funkcja wy�wietlaj�ca r�k� komputera - wersja dla drugiej cz�ci gry
	void wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6]);					//funkcja wy�wietlaj�ca r�k� cz�owieka - wersja dla drugiej cz�ci gry
	Karta & wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks);		//funkcja wy�wietlaj�ca kart� wy�o�on� przez komputer
	Karta & wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks);		//funkcja wy�wietlaj�ca kart� wy�o�on� przez cz�owieka	
	void zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska);					//funkcja zakrywaj�ca puste miejsce w r�ce komputera
	void zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska);					//funkcja zakrywaj�ca puste miejsce w r�ce cz�owieka
	void zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska);		//funkcja zakrywaj�ca kart� wy�o�on� przez komputer
	void zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska);		//funkcja zakrywaj�ca kart� wy�o�on� przez cz�owieka
	void wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta karta);			//funkcja wy�wietlaj�ca wygran� lew� komputera
	void wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta karta);			//funkcja wy�wietlaj�ca wygran� lew� cz�owieka
	
	//Karta jakaKarta(int indeks);							//funkcja sprawdzaj�ca, jaka karta jest pod podanym indeksem
	//int dodajDuzePunkty(int punkty);						//funkcja dodaj�ca du�e punkty
	//void wyswietlZbiorLew();								//funkcja wy�wietlaj�ca zbi�r lew
	//int sprawdz_warunek_podmiany(); //funkcja sprawdzaj�ca warunek podmiany dziewi�tki w kolorze atutowym na kart� ze spodu stosu
	//void podmien(Talia & talia, int indeks); //funkcja podmieniaj�ca dziewi�tk� atutow� na kart� ze spodu stosu
	//int sprawdz_meldunek(); //funkcja sprawdzaj�ca, czy jest meldunek
};
