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
	Rozgrywka();
	int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral); //funkcja porównuj¹ca wy³o¿one karty
	int dodajPunkty(Gracz & komputer, Gracz & czlowiek, int punkty);
	void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty); //funkcja pobieraj¹ca karty ze stosu w odpowiedniej kolejnoœci
	int rozstrzygnijZwyciestwo(int punktyKomputera, int punktyCzlowieka);
	std::string powiedzKtoWygral(int punkty);
	void dodajLewe(Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral);
	void ruchKomputeraPierwszy1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void ruchKomputeraDrugi1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void ruchCzlowieka1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, const float w, const float s, sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void ruchKomputeraPierwszy2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void ruchKomputeraDrugi2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void ruchCzlowieka2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, const float w, const float s, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], const float x, const float y, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], int tabKomputera[6], int tabCzlowieka[6], const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);
	void wyswietlStos(sf::RenderWindow & window, const float x, const float y);
	void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);
	void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const float x, const float y);
	void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);
	void wyswietlWygranaLewe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral, const float x, const float y[2]);
	void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer, const float xt, const float yt, const float xp, const float yp);
	void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek, const float xt, const float yt, const float xp, const float yp);
	void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float xz, const float yz);
	void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas, const float xc, const float yc, const float xcz, const float ycz);
	void wyswietlInformacjeKoncowe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int czas, const float xz, const float yz, const float xc, const float yc, const float xcz, const float ycz);
};