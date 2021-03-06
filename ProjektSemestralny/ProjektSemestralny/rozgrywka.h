#pragma once
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <thread>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "gracz.h"

class Rozgrywka
{
public:
	Rozgrywka();																														//konstruktor obiektu klasy Rozgrywka
	int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral);							//funkcja porównująca wyłożone karty
	int dodajPunkty(Gracz & komputer, Gracz & czlowiek, int punkty);																	//funkcja dodająca punkty graczowi, który zwyciężył w rozgrywce
	void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty);		//funkcja pobierająca karty ze stosu w odpowiedniej kolejności
	std::string powiedzKtoWygral(int punkty);																							//funkcja informująca o tym, kto wygrał rozgrywkę
	void dodajLewe(Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral);					//funkcja dodająca lewę do zbioru lew gracza, który zwyciężył w rozgrywce
	void ruchKomputeraPierwszy1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																//funkcja umożliwiająca wykonanie ruchu komputera jako pierwszego wykładającego kartę - wersja dla pierwszej części gry
	void ruchKomputeraDrugi1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);												//funkcja umożliwiająca wykonanie ruchu komputera jako drugiego wykładającego kartę - wersja dla pierwszej części gry
	void ruchCzlowieka1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, const float w, const float s, sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umożliwiająca wykonanie ruchu człowieka - wersja dla pierwszej części gry
	void ruchKomputeraPierwszy2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);											//funkcja umożliwiająca wykonanie ruchu komputera jako pierwszego wykładającego kartę - wersja dla drugiej części gry
	void ruchKomputeraDrugi2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umożliwiająca wykonanie ruchu komputera jako drugiego wykładającego kartę - wersja dla drugiej części gry
	void ruchCzlowieka2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, const float w, const float s, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);		//funkcja umożliwiająca wykonanie ruchu człowieka - wersja dla drugiej części gry
	void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], const float x, const float y, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																									//funkcja wyświetlająca stół gry - wersja dla pierwszej części gry
	void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], int tabKomputera[6], int tabCzlowieka[6], const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																						//funkcja wyświetlająca stół gry - wersja dla drugiej części gry
	void wyswietlStos(sf::RenderWindow & window, const float x, const float y);																																	//funkcja wyświetlająca stos kart
	void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																											//funkcja zakrywająca stos kart
	void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const float x, const float y);																											//funkcja wyświetlająca kartę wyznaczającą kolor atutowy
	void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																									//funkcja zakrywająca kartę wyznaczającą kolor atutowy
	void wyswietlWygranaLewe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral, const float x, const float y[2]);					//funkcja wyświetlająca wygrywającą kartę należącą do lewy
	void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer, const float xt, const float yt, const float xp, const float yp);																	//funkcja wyświetlająca punkty zdobyte przez komputer
	void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek, const float xt, const float yt, const float xp, const float yp);																	//funkcja wyświetlająca punkty zdobyte przez człowieka
	void wyswietlTekstPowitalny(sf::RenderWindow & window, const float xt, const float yt);
	void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float xz, const float yz);																				//funkcja wyświetlająca informację o zwycięzcy rozgrywki
	void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas, const float xc, const float yc, const float xcz, const float ycz);																	//funkcja wyświetlająca informację o czasie trwania rozgrywki
	void wyswietlInformacjeKoncowe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int czas, const float xz, const float yz, const float xc, const float yc, const float xcz, const float ycz);		//funkcja wyświetlająca informacje końcowe o rozgrywce
	template <class T>
	T rozstrzygnijZwyciestwoT(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	};
};