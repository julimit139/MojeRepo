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
	int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral);							//funkcja porównuj¹ca wy³o¿one karty
	int dodajPunkty(Gracz & komputer, Gracz & czlowiek, int punkty);																	//funkcja dodaj¹ca punkty graczowi, który zwyciê¿y³ w rozgrywce
	void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty);		//funkcja pobieraj¹ca karty ze stosu w odpowiedniej kolejnoœci
	std::string powiedzKtoWygral(int punkty);																							//funkcja informuj¹ca o tym, kto wygra³ rozgrywkê
	void dodajLewe(Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral);					//funkcja dodaj¹ca lewê do zbioru lew gracza, który zwyciê¿y³ w rozgrywce
	void ruchKomputeraPierwszy1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																//funkcja umo¿liwiaj¹ca wykonanie ruchu komputera jako pierwszego wyk³adaj¹cego kartê - wersja dla pierwszej czêœci gry
	void ruchKomputeraDrugi1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);												//funkcja umo¿liwiaj¹ca wykonanie ruchu komputera jako drugiego wyk³adaj¹cego kartê - wersja dla pierwszej czêœci gry
	void ruchCzlowieka1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, const float w, const float s, sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umo¿liwiaj¹ca wykonanie ruchu cz³owieka - wersja dla pierwszej czêœci gry
	void ruchKomputeraPierwszy2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);											//funkcja umo¿liwiaj¹ca wykonanie ruchu komputera jako pierwszego wyk³adaj¹cego kartê - wersja dla drugiej czêœci gry
	void ruchKomputeraDrugi2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);							//funkcja umo¿liwiaj¹ca wykonanie ruchu komputera jako drugiego wyk³adaj¹cego kartê - wersja dla drugiej czêœci gry
	void ruchCzlowieka2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, const float w, const float s, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);		//funkcja umo¿liwiaj¹ca wykonanie ruchu cz³owieka - wersja dla drugiej czêœci gry
	void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], const float x, const float y, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																									//funkcja wyœwietlaj¹ca stó³ gry - wersja dla pierwszej czêœci gry
	void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], int tabKomputera[6], int tabCzlowieka[6], const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc);																																						//funkcja wyœwietlaj¹ca stó³ gry - wersja dla drugiej czêœci gry
	void wyswietlStos(sf::RenderWindow & window, const float x, const float y);																																	//funkcja wyœwietlaj¹ca stos kart
	void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																											//funkcja zakrywaj¹ca stos kart
	void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const float x, const float y);																											//funkcja wyœwietlaj¹ca kartê wyznaczaj¹c¹ kolor atutowy
	void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y);																									//funkcja zakrywaj¹ca kartê wyznaczaj¹c¹ kolor atutowy
	void wyswietlWygranaLewe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral, const float x, const float y[2]);					//funkcja wyœwietlaj¹ca wygrywaj¹c¹ kartê nale¿¹c¹ do lewy
	void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer, const float xt, const float yt, const float xp, const float yp);																	//funkcja wyœwietlaj¹ca punkty zdobyte przez komputer
	void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek, const float xt, const float yt, const float xp, const float yp);																	//funkcja wyœwietlaj¹ca punkty zdobyte przez cz³owieka
	void wyswietlTekstPowitalny(sf::RenderWindow & window, const float xt, const float yt);
	void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float xz, const float yz);																				//funkcja wyœwietlaj¹ca informacjê o zwyciêzcy rozgrywki
	void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas, const float xc, const float yc, const float xcz, const float ycz);																	//funkcja wyœwietlaj¹ca informacjê o czasie trwania rozgrywki
	void wyswietlInformacjeKoncowe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int czas, const float xz, const float yz, const float xc, const float yc, const float xcz, const float ycz);		//funkcja wyœwietlaj¹ca informacje koñcowe o rozgrywce
	template <class T>
	T rozstrzygnijZwyciestwoT(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	};
};