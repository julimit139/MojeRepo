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


void wyswietlStos(sf::RenderWindow & window, const int wspolrzednaStosuX, const int wspolrzednaStosuY);
void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const int wspolrzednaStosuX, const int wspolrzednaStosuY);
void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek);
void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia);
void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska);

int rozstrzygnijZwyciestwo(int malePunktyKomputera, int malePunktyCzlowieka);

//void wyswietlTimer();


int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral); //funkcja porównuj¹ca wy³o¿one karty
int dodajMalePunkty(Gracz & komputer, Gracz & czlowiek, int punkty);
void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty); //funkcja pobieraj¹ca karty ze stosu w odpowiedniej kolejnoœci



int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);
	sf::RectangleShape maskaKomputera(sf::Vector2f(130, 177));
	sf::RectangleShape maskaCzlowieka(sf::Vector2f(130, 177));
	sf::RectangleShape maskaStosu(sf::Vector2f(130, 177));

	sf::Clock clock;

	//std::thread timer(wyswietlTimer);



	Talia talia;
	talia.tasujKarty();

	Kolor kolorAtutowy = talia.odczytajKolorAtutowy();

	Gracz komputer(talia);
	Gracz czlowiek(talia);

	wyswietlStol(window, komputer, czlowiek);
	Sleep(1000);


	wyswietlStol(window, komputer, czlowiek);
	wyswietlKolorAtutowy(window, talia);
	window.display();
	Sleep(1000);



	wyswietlStol(window, komputer, czlowiek);
	zakryjKolorAtutowy(window, maskaKomputera);
	window.display();
	Sleep(1000);

	
	
	std::string ktoWygral = "komputer";
	Karta kartaKomputera;
	Karta kartaCzlowieka;


	while (window.isOpen())
	{	
		sf::Time elapsed = clock.getElapsedTime();
		std::cout << elapsed.asSeconds() << std::endl;
		clock.restart();


		//pierwsza czêœæ gry - ze stosem kart
		while (talia.odczytajDlugoscTalii() != 0)
		{
			//wyswietlStol(window, komputer, czlowiek);
			//Sleep(1000);



			if (ktoWygral == "komputer")
			{
				//Ruch komputera - pierwszy ruch nale¿y do komputera

				wyswietlStol(window, komputer, czlowiek);
				kartaKomputera = komputer.wyswietlWylozonaKarteKomputera(window, 0);
				komputer.zakryjPusteMiejsceWReceKomputera(window, 0, wspolrzedneRekiX, maskaKomputera);
				window.display();




				//Ruch gracza


				int x, y, indeks;
				bool wyjscie = false;
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
								x = sf::Mouse::getPosition(window).x;
								y = sf::Mouse::getPosition(window).y;
								indeks = czlowiek.wybierzKarte(window, x, y);
								wyjscie = true;
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

				wyswietlStol(window, komputer, czlowiek);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);

			}

			else if (ktoWygral == "czlowiek")
			{
				//Ruch gracza
				int x, y, indeks;
				bool wyjscie = false;
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
								x = sf::Mouse::getPosition(window).x;
								y = sf::Mouse::getPosition(window).y;
								indeks = czlowiek.wybierzKarte(window, x, y);
								wyjscie = true;
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

				wyswietlStol(window, komputer, czlowiek);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);


				//Ruch komputera
				kartaKomputera = komputer.dobierzKarte1(kartaCzlowieka);

				wyswietlStol(window, komputer, czlowiek);
				komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera));
				komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), wspolrzedneRekiX, maskaKomputera);
				window.display();
				Sleep(1000);






			}


			int punkty = porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			if (punkty < 0)
			{
				ktoWygral = "komputer";
			}
			else
			{
				ktoWygral = "czlowiek";
			}
			dodajMalePunkty(komputer, czlowiek, punkty);

			Sleep(1000);

			wyswietlStol(window, komputer, czlowiek);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaCzlowieka);
			window.display();
			Sleep(1000);

			pobierzKarty(komputer, czlowiek, kartaKomputera, kartaCzlowieka, talia, punkty);

			wyswietlStol(window, komputer, czlowiek);
			Sleep(1000);
		}




		//druga czêœæ gry - bez stosu kart
		wyswietlStol(window, komputer, czlowiek);
		zakryjStos(window, maskaStosu, wspolrzednaStosuX, wspolrzednaStosuY);
		window.display();
		Sleep(1000);
		
		
		int tablicaKomputera[6] = { 1, 2, 3, 4, 5, 6 };
		int tablicaCzlowieka[6] = { 1, 2, 3, 4, 5, 6 };

		for (int i = 0; i < rozmiar_reki; i++)
		{
			//wyswietlStol(window, komputer, czlowiek);
			//Sleep(2000);

			if (ktoWygral == "komputer")
			{
				//ruch komputera
				int ind = 0;
				for (int i = 0; i < rozmiar_reki; i++)
				{
					if (tablicaKomputera[i] != 0)
					{
						ind = i;
						break;
					}
				}
				kartaKomputera = komputer.wezKarteSpodIndeksu2(ind, tablicaKomputera);

				wyswietlStol(window, komputer, czlowiek);
				komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera));
				komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), wspolrzedneRekiX, maskaKomputera);
				window.display();
				Sleep(1000);

				//Ruch gracza
				int x, y, indeks;
				bool wyjscie = false;
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
								x = sf::Mouse::getPosition(window).x;
								y = sf::Mouse::getPosition(window).y;
								indeks = czlowiek.wybierzKarte(window, x, y);
								wyjscie = true;
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
				tablicaCzlowieka[indeks] = 0;

				wyswietlStol(window, komputer, czlowiek);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);

			}
			else if (ktoWygral == "czlowiek")
			{
				//Ruch gracza
				int x, y, indeks;
				bool wyjscie = false;
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
								x = sf::Mouse::getPosition(window).x;
								y = sf::Mouse::getPosition(window).y;
								indeks = czlowiek.wybierzKarte(window, x, y);
								wyjscie = true;
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
				tablicaCzlowieka[indeks] = 0;

				wyswietlStol(window, komputer, czlowiek);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);

				//ruch komputera
				kartaKomputera = komputer.dobierzKarte2(kartaCzlowieka, tablicaKomputera);
				tablicaKomputera[komputer.znajdzIndeks(kartaKomputera)] = 0;

				wyswietlStol(window, komputer, czlowiek);
				komputer.wyswietlWylozonaKarteKomputera(window, komputer.znajdzIndeks(kartaKomputera));
				komputer.zakryjPusteMiejsceWReceKomputera(window, komputer.znajdzIndeks(kartaKomputera), wspolrzedneRekiX, maskaKomputera);
				window.display();
				Sleep(1000);

			}

			int punkty = porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			if (punkty < 0)
			{
				ktoWygral = "komputer";
			}
			else
			{
				ktoWygral = "czlowiek";
			}
			dodajMalePunkty(komputer, czlowiek, punkty);

			wyswietlStol(window, komputer, czlowiek);
			Sleep(1000);

		}

		




	}

	
	


	

	return 0;
	getchar();
}

















void wyswietlStos(sf::RenderWindow & window, const int wspolrzednaStosuX, const int wspolrzednaStosuY)
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(wspolrzednaStosuX, wspolrzednaStosuY));
	window.draw(sprite);
}

void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const int wspolrzednaStosuX, const int wspolrzednaStosuY)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(wspolrzednaStosuX, wspolrzednaStosuY);
	window.draw(maska);
}

void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window, wspolrzednaStosuX, wspolrzednaStosuY);
	komputer.wyswietlRekeKomputera(window);
	czlowiek.wyswietlRekeCzlowieka(window);
	window.display();
}

void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia)
{
	talia.pokazKarteAtutowa().wyswietlKarte(window, 519, 245);
}


void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(519, 245);
	window.draw(maska);
	//window.display();
}




int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral)
{
	int punkty = 0;
	if (kartaKomputera.odczytajKolor() == kolorAtutowy)
	{
		if (kartaCzlowieka.odczytajKolor() == kolorAtutowy)
		{
			//if (kartaKomputera.odczytajWartosc() > kartaCzlowieka.odczytajWartosc())
			if(std::max(kartaKomputera.odczytajWartosc(), kartaCzlowieka.odczytajWartosc()) == kartaKomputera.odczytajWartosc())
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

int dodajMalePunkty(Gracz & komputer, Gracz & czlowiek, int punkty) //dodaje punkty odpowiedniemu graczowi; je¿eli punkty < 0, to dodaje komputerowi, w przeciwnym wypadku cz³owiekowi
{
	if (punkty < 0)
	{
		punkty = -punkty; //liczbê uzyskanych punktów zamienia na przeciwn¹, dodatni¹ i dodaje do liczby ma³ych punktów komputera
		komputer.dodajMalePunkty(punkty);
		return punkty;
	}
	else
	{
		czlowiek.dodajMalePunkty(punkty); //dodaje punkty do liczby ma³ych punktów cz³owieka
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

/*void wyswietlTimer()
{

	


}*/

int rozstrzygnijZwyciestwo(int malePunktyKomputera, int malePunktyCzlowieka)
{
	if (malePunktyKomputera > malePunktyCzlowieka)
		return malePunktyKomputera;
	else
		return malePunktyCzlowieka;
}

template <class T>
T rozstrzygnijZwyciestwoT(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
