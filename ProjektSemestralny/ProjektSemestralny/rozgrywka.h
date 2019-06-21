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
	int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral);							//funkcja por�wnuj�ca wy�o�one karty
	int dodajPunkty(Gracz & komputer, Gracz & czlowiek, int punkty);																	//funkcja dodaj�ca punkty graczowi, kt�ry zwyci�y� w rozgrywce
	void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty);		//funkcja pobieraj�ca karty ze stosu w odpowiedniej kolejno�ci
	std::string powiedzKtoWygral(int punkty);																							//funkcja informuj�ca o tym, kto wygra� rozgrywk�
	void dodajLewe(Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral);					//funkcja dodaj�ca lew� do zbioru lew gracza, kt�ry zwyci�y� w rozgrywce
	void ruchKomputeraPierwszy1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																//funkcja umo�liwiaj�ca wykonanie ruchu komputera jako pierwszego wyk�adaj�cego kart� - wersja dla pierwszej cz�ci gry
	void ruchKomputeraDrugi1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);												//funkcja umo�liwiaj�ca wykonanie ruchu komputera jako drugiego wyk�adaj�cego kart� - wersja dla pierwszej cz�ci gry
	void ruchCzlowieka1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, const float w, const float s, sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umo�liwiaj�ca wykonanie ruchu cz�owieka - wersja dla pierwszej cz�ci gry
	void ruchKomputeraPierwszy2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);											//funkcja umo�liwiaj�ca wykonanie ruchu komputera jako pierwszego wyk�adaj�cego kart� - wersja dla drugiej cz�ci gry
	void ruchKomputeraDrugi2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umo�liwiaj�ca wykonanie ruchu komputera jako drugiego wyk�adaj�cego kart� - wersja dla drugiej cz�ci gry
	void ruchCzlowieka2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, const float w, const float s, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);		//funkcja umo�liwiaj�ca wykonanie ruchu cz�owieka - wersja dla drugiej cz�ci gry
	void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], const float x, const float y, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																									//funkcja wy�wietlaj�ca st� gry - wersja dla pierwszej cz�ci gry
	void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], int tabKomputera[6], int tabCzlowieka[6], const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																						//funkcja wy�wietlaj�ca st� gry - wersja dla drugiej cz�ci gry
	void wyswietlStos(sf::RenderWindow & window, const float x, const float y);																																	//funkcja wy�wietlaj�ca stos kart
	void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																											//funkcja zakrywaj�ca stos kart
	void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const float x, const float y);																											//funkcja wy�wietlaj�ca kart� wyznaczaj�c� kolor atutowy
	void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																									//funkcja zakrywaj�ca kart� wyznaczaj�c� kolor atutowy
	void wyswietlWygranaLewe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral, const float x, const float y[2]);					//funkcja wy�wietlaj�ca wygrywaj�c� kart� nale��c� do lewy
	void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer, const float xt, const float yt, const float xp, const float yp);																	//funkcja wy�wietlaj�ca punkty zdobyte przez komputer
	void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek, const float xt, const float yt, const float xp, const float yp);																	//funkcja wy�wietlaj�ca punkty zdobyte przez cz�owieka
	void wyswietlTekstPowitalny(sf::RenderWindow & window, const float xt, const float yt);
	void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float xz, const float yz);																				//funkcja wy�wietlaj�ca informacj� o zwyci�zcy rozgrywki
	void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas, const float xc, const float yc, const float xcz, const float ycz);																	//funkcja wy�wietlaj�ca informacj� o czasie trwania rozgrywki
	void wyswietlInformacjeKoncowe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int czas, const float xz, const float yz, const float xc, const float yc, const float xcz, const float ycz);		//funkcja wy�wietlaj�ca informacje ko�cowe o rozgrywce
	template <class T>
	T rozstrzygnijZwyciestwoT(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	};
};