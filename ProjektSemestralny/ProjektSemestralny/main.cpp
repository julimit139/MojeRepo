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

//Deklaracje funkcji zdefiniownych poni¿ej funkcji main

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
void threadTick(int* timer, bool* end);
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




int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);
	
	sf::RectangleShape maskaKomputera(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	sf::RectangleShape maskaCzlowieka(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	sf::RectangleShape maskaStosu(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	
	bool wyjscie = false;
	int timer = 0;
	bool endTimer = false;
	std::thread Timer(threadTick, &timer, &endTimer);
	

	Talia talia;
	talia.tasujKarty();

	Kolor kolorAtutowy = talia.odczytajKolorAtutowy();

	Gracz komputer(talia);
	Gracz czlowiek(talia);

	wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	Sleep(1000);

	wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	wyswietlKolorAtutowy(window, talia, wspolrzednaKoloruAtutowegoX, wspolrzednaKoloruAtutowegoY);
	window.display();
	Sleep(1500);

	wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	zakryjKolorAtutowy(window, maskaKomputera, wspolrzednaKoloruAtutowegoX, wspolrzednaKoloruAtutowegoY);
	window.display();
	Sleep(1000);


	std::string ktoWygral = "komputer";
	Karta kartaKomputera;
	Karta kartaCzlowieka;

	while (window.isOpen())
	{	
		//pierwsza czêœæ gry - ze stosem kart
		while (talia.odczytajDlugoscTalii() != 0)
		{
			wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			Sleep(1000);

			if (ktoWygral == "komputer")
			{
				ruchKomputeraPierwszy1(window, komputer, czlowiek, kartaKomputera, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				ruchCzlowieka1(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			}
			else if (ktoWygral == "czlowiek")
			{
				ruchCzlowieka1(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				ruchKomputeraDrugi1(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			}

			int punkty = porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			ktoWygral = powiedzKtoWygral(punkty);
			//dodajLewe(komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral);
			dodajPunkty(komputer, czlowiek, punkty);

			Sleep(1000);
			wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			window.display();
			Sleep(1000);

			wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaCzlowieka);
			window.display();
			Sleep(500);

			wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			wyswietlWygranaLewe(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral, wspolrzednaLewX, wspolrzedneLewY);
			window.display();
			Sleep(1500);

			pobierzKarty(komputer, czlowiek, kartaKomputera, kartaCzlowieka, talia, punkty);
		}

	
		//druga czêœæ gry - bez stosu kart
		int tablicaKomputera[6] = { 1, 2, 3, 4, 5, 6 };
		int tablicaCzlowieka[6] = { 1, 2, 3, 4, 5, 6 };


		wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
		Sleep(1000);
		
		for (int i = 0; i < rozmiarReki; i++)
		{
			wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			Sleep(2000);

			if (ktoWygral == "komputer")
			{
				ruchKomputeraPierwszy2(window, komputer, czlowiek, kartaKomputera, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, tablicaKomputera, tablicaCzlowieka, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				ruchCzlowieka2(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, tablicaKomputera, tablicaCzlowieka, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

			}
			else if (ktoWygral == "czlowiek")
			{
				ruchCzlowieka2(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, tablicaKomputera, tablicaCzlowieka, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				ruchKomputeraDrugi2(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, tablicaKomputera, tablicaCzlowieka, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

			}

			int punkty = porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			ktoWygral = powiedzKtoWygral(punkty);
			//dodajLewe(komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral);
			dodajPunkty(komputer, czlowiek, punkty);

			Sleep(1000);
			wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			window.display();
			Sleep(1000);

			wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaCzlowieka);
			window.display();
			Sleep(500);

			wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			wyswietlWygranaLewe(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral, wspolrzednaLewX, wspolrzedneLewY);
			window.display();
			Sleep(1500);

		}

		wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
		Sleep(1500);
		
		endTimer = true;
		Sleep(2000);

		//zakoñczenie gry
		wyswietlInformacjeKoncowe(window, komputer, czlowiek, timer, wspolrzednaTekstuOWygranejX, wspolrzednaTekstuOWygranejY, wspolrzednaTekstuOCzasieX, wspolrzednaTekstuOCzasieY, wspolrzednaCzasuX, wspolrzednaCzasuY);

		endTimer = true;
		Timer.join();

		window.close();
	}

	return 0;
	getchar();
}





//Definicje funkcji zadeklarowanych powy¿ej funkcji main

int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral)
{
	int punkty = 0;
	if (kartaKomputera.odczytajKolor() == kolorAtutowy)
	{
		if (kartaCzlowieka.odczytajKolor() == kolorAtutowy)
		{
			if (std::max(kartaKomputera.odczytajWartosc(), kartaCzlowieka.odczytajWartosc()) == kartaKomputera.odczytajWartosc())
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz³owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
		}
		else
		{
			punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
			punkty -= kartaCzlowieka.odczytajWartosc();
		}

	}
	if (kartaKomputera.odczytajKolor() != kolorAtutowy)
	{
		if (kartaCzlowieka.odczytajKolor() != kolorAtutowy)
		{
			if ((kartaKomputera.odczytajWartosc() == kartaCzlowieka.odczytajWartosc()) && (ktoWygral == "komputer"))
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else if ((kartaKomputera.odczytajWartosc() == kartaCzlowieka.odczytajWartosc()) && (ktoWygral == "czlowiek"))
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz³owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
			else if (std::max(kartaKomputera.odczytajWartosc(), kartaCzlowieka.odczytajWartosc()) == kartaKomputera.odczytajWartosc())
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz³owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
		}
		else
		{
			punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz³owieka
			punkty += kartaCzlowieka.odczytajWartosc();
		}
	}
	return punkty;
}

int dodajPunkty(Gracz & komputer, Gracz & czlowiek, int punkty) //dodaje punkty odpowiedniemu graczowi; je¿eli punkty < 0, to dodaje komputerowi, w przeciwnym wypadku cz³owiekowi
{
	if (punkty < 0)
	{
		punkty = -punkty; //liczbê uzyskanych punktów zamienia na przeciwn¹, dodatni¹ i dodaje do liczby ma³ych punktów komputera
		komputer.dodajPunkty(punkty);
		return punkty;
	}
	else
	{
		czlowiek.dodajPunkty(punkty); //dodaje punkty do liczby ma³ych punktów cz³owieka
		return punkty;
	}
}

void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty) //pobiera karty poczynaj¹c od tego gracza, który wzi¹³ lew¹
{
	if (punkty < 0)
	{

		komputer.pobierzKarte(talia, komputer.znajdzIndeks(kartaKomputera)); //lew¹ wzi¹³ komputer, wiêc najpierw pobiera siê karta dla niego, potem dla cz³owieka
		czlowiek.pobierzKarte(talia, czlowiek.znajdzIndeks(kartaCzlowieka));
	}
	else
	{
		czlowiek.pobierzKarte(talia, czlowiek.znajdzIndeks(kartaCzlowieka)); //lew¹ wzi¹³ cz³owiek, wiêc najpierw pobiera siê karta dla niego, potem dla komputera
		komputer.pobierzKarte(talia, komputer.znajdzIndeks(kartaKomputera));
	}
}

int rozstrzygnijZwyciestwo(int punktyKomputera, int punktyCzlowieka)
{
	if (punktyKomputera > punktyCzlowieka)
		return punktyKomputera;
	else
		return punktyCzlowieka;
}

template <class T>
T rozstrzygnijZwyciestwoT(T a, T b)
{
	if (a.fun() > b.fun())
		return a;
	else
		return b;
}

std::string powiedzKtoWygral(int punkty)
{
	std::string ktoWygral;
	if (punkty < 0)
	{
		ktoWygral = "komputer";
	}
	else
	{
		ktoWygral = "czlowiek";
	}
	return ktoWygral;
}

void dodajLewe(Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral)
{
	if (ktoWygral == "komputer")
	{
		komputer.dodajLewe(kartaKomputera, kartaCzlowieka);
	}
	else if (ktoWygral == "czlowiek")
	{
		czlowiek.dodajLewe(kartaKomputera, kartaCzlowieka);
	}
}

void ruchKomputeraPierwszy1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	wyswietlStol1(window, komputer, czlowiek, X, Y, x, y, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	kartaKomputera = komputer.wyswietlWylozonaKarteKomputera(window, 0, xw, yw);
	komputer.zakryjPusteMiejsceWReceKomputera(window, 0, X, Y, maskaKomputera);
	window.display();
}

void ruchKomputeraDrugi1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	kartaKomputera = komputer.dobierzKarte1(kartaCzlowieka);
	wyswietlStol1(window, komputer, czlowiek, X, Y, x, y, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera), xw, yw);
	komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), X, Y, maskaKomputera);
	window.display();
	Sleep(1000);
}

void ruchCzlowieka1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float x, const float y, const float xw, const float yw, const float w, const float s, sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	int myszx, myszy, indeks;
	sf::Event event;
	while (!wyjscie)
	{
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				switch (event.key.code)
				{
				case sf::Mouse::Left:
				{
					myszx = sf::Mouse::getPosition(window).x;
					myszy = sf::Mouse::getPosition(window).y;
					indeks = czlowiek.wybierzKarte(window, myszx, myszy, X, Y, w, s);
					if (indeks != 7)
					{
						wyjscie = true;
					}
					break;
				}
				}
				break;
			}
			case sf::Event::Closed:
			{
				window.close();
				break;
			}


			}
		}
	}
	wyjscie = false;
	wyswietlStol1(window, komputer, czlowiek, X, Y, x, y, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks, xw, yw);
	czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, X, Y, maskaCzlowieka);
	window.display();
	Sleep(1000);
}

void ruchKomputeraPierwszy2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	int ind = 0;
	for (int i = 0; i < rozmiarReki; i++)
	{
		if (tablicaKomputera[i] != 0)
		{
			ind = i;
			break;
		}
	}
	kartaKomputera = komputer.wezKarteSpodIndeksu2(ind, tablicaKomputera);
	wyswietlStol2(window, komputer, czlowiek, X, Y, tablicaKomputera, tablicaCzlowieka, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera), xw, yw);
	komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), X, Y, maskaKomputera);
	window.display();
	Sleep(1000);
}

void ruchKomputeraDrugi2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaKomputera, Karta kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaKomputera, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	kartaKomputera = komputer.dobierzKarte2(kartaCzlowieka, tablicaKomputera);
	tablicaKomputera[komputer.znajdzIndeks(kartaKomputera)] = 0;
	wyswietlStol2(window, komputer, czlowiek, X, Y, tablicaKomputera, tablicaCzlowieka, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera), xw, yw);
	komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), X, Y, maskaKomputera);
	window.display();
	Sleep(1000);
}

void ruchCzlowieka2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta & kartaCzlowieka, const float X[6], const float Y[2], const float xw, const float yw, const float w, const float s, int tablicaKomputera[6], int tablicaCzlowieka[6], sf::RectangleShape maskaCzlowieka, bool & wyjscie, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	int myszx, myszy, indeks;
	sf::Event event;
	while (!wyjscie)
	{
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				switch (event.key.code)
				{
				case sf::Mouse::Left:
				{
					myszx = sf::Mouse::getPosition(window).x;
					myszy = sf::Mouse::getPosition(window).y;
					indeks = czlowiek.wybierzKarte(window, myszx, myszy, X, Y, w, s);
					if (indeks != 7)
					{
						wyjscie = true;
					}
					break;
				}
				}
				break;
			}
			case sf::Event::Closed:
			{
				window.close();
				break;
			}


			}
		}
	}
	wyjscie = false;
	tablicaCzlowieka[indeks] = 0;
	wyswietlStol2(window, komputer, czlowiek, X, Y, tablicaKomputera, tablicaCzlowieka, xtk, ytk, xpk, ypk, xtc, ytc, xpc, ypc);
	kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks, xw, yw);
	czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, X, Y, maskaCzlowieka);
	window.display();
	Sleep(1000);
}

void threadTick(int* timer, bool* end)
{
	while (!(*end))
	{
		Sleep(1000);
		(*timer)++;
		std::cout << *timer << std::endl;
	}
}

void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], const float x, const float y, const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window, x, y);
	komputer.wyswietlRekeKomputera1(window, X, Y);
	czlowiek.wyswietlRekeCzlowieka1(window, X, Y);
	wyswietlPunktyKomputera(window, komputer, xtk, ytk, xpk, ypk);
	wyswietlPunktyCzlowieka(window, czlowiek, xtc, ytc, xpc, ypc);
	window.display();
}

void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float X[6], const float Y[2], int tabKomputera[6], int tabCzlowieka[6], const float xtk, const float ytk, const float xpk, const float ypk, const float xtc, const float ytc, const float xpc, const float ypc)
{
	window.clear(sf::Color(30, 91, 6, 1));
	komputer.wyswietlRekeKomputera2(window, tabKomputera, X, Y);
	czlowiek.wyswietlRekeCzlowieka2(window, tabCzlowieka, X, Y);
	wyswietlPunktyKomputera(window, komputer, xtk, ytk, xpk, ypk);
	wyswietlPunktyCzlowieka(window, czlowiek, xtc, ytc, xpc, ypc);
	window.display();
}

void wyswietlStos(sf::RenderWindow & window, const float x, const float y)
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	window.draw(sprite);
}

void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x, y);
	window.draw(maska);
}

void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const float x, const float y)
{
	talia.pokazKarteAtutowa().wyswietlKarte(window, x, y);
}

void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const float x, const float y)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x, y);
	window.draw(maska);
}

void wyswietlWygranaLewe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, std::string ktoWygral, const float x, const float y[2])
{
	if (ktoWygral == "komputer")
	{
		komputer.wyswietlWygranaLeweKomputera(window, kartaKomputera, x, y);
	}
	else if (ktoWygral == "czlowiek")
	{
		czlowiek.wyswietlWygranaLeweCzlowieka(window, kartaCzlowieka, x, y);
	}
}

void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer, const float xt, const float yt, const float xp, const float yp)
{
	std::string nazwa = "KOMPUTER";
	std::string punkty = std::to_string(komputer.odczytajLiczbePunktow());
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		font.loadFromFile("HeadlinerNo45.ttf");
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(nazwa);
	text1.setCharacterSize(25);
	text1.setPosition(sf::Vector2f(xt, yt));
	text1.setFillColor(sf::Color::White);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(punkty);
	text2.setCharacterSize(25);
	text2.setPosition(sf::Vector2f(xp, yp));
	text2.setFillColor(sf::Color::White);

	window.draw(text1);
	window.draw(text2);
}

void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek, const float xt, const float yt, const float xp, const float yp)
{
	std::string nazwa = "TY";
	std::string punkty = std::to_string(czlowiek.odczytajLiczbePunktow());
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		font.loadFromFile("HeadlinerNo45.ttf");
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(nazwa);
	text1.setCharacterSize(25);
	text1.setPosition(sf::Vector2f(xt, yt));
	text1.setFillColor(sf::Color::White);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(punkty);
	text2.setCharacterSize(25);
	text2.setPosition(sf::Vector2f(xp, yp));
	text2.setFillColor(sf::Color::White);

	window.draw(text1);
	window.draw(text2);
}

void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const float xz, const float yz)
{
	std::string tekst;
	int wygrany = rozstrzygnijZwyciestwo(komputer.odczytajLiczbePunktow(), czlowiek.odczytajLiczbePunktow());
	if (wygrany == komputer.odczytajLiczbePunktow())
	{
		tekst = "Ta rozgrywke wygral komputer!";
	}
	else
	{
		tekst = "Ta rozgrywke wygrales Ty!";
	}

	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		font.loadFromFile("HeadlinerNo45.ttf");
	}
	sf::Text text;
	text.setFont(font);
	text.setString(tekst);
	text.setCharacterSize(45);
	text.setPosition(sf::Vector2f(xz, yz));
	text.setFillColor(sf::Color::White);

	window.draw(text);
}

void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas, const float xc, const float yc, const float xcz, const float ycz)
{
	std::string tekst = "Czas trwania rozgrywki (sekundy): ";
	std::string czasGry = std::to_string(czas);
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		font.loadFromFile("HeadlinerNo45.ttf");
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(tekst);
	text1.setCharacterSize(45);
	text1.setPosition(sf::Vector2f(xc, yc));
	text1.setFillColor(sf::Color::White);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(czasGry);
	text2.setCharacterSize(45);
	text2.setPosition(sf::Vector2f(xcz, ycz));
	text2.setFillColor(sf::Color::White);

	window.draw(text1);
	window.draw(text2);
}

void wyswietlInformacjeKoncowe(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int czas, const float xz, const float yz, const float xc, const float yc, const float xcz, const float ycz)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlInformacjeOZwyciestwie(window, komputer, czlowiek, xz, yz);
	wyswietlInformacjeOCzasieGry(window, czas, xc, yc, xcz, ycz);
	window.display();
	Sleep(4000);
}