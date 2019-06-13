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

void threadTick(int* timer, bool* end)
{
	while (!(*end))
	{
		Sleep(1000);
		(*timer)++;
		std::cout << *timer << std::endl;
	}
};

void wyswietlStos(sf::RenderWindow & window, const int X, const int Y);
void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const int X, const int Y);
void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const int X, const int Y);
void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int tabKomputera[6], int tabCzlowieka[6]);
void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const int X, const int Y);
void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const int X, const int Y);

void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer);
void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek);

void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek);
void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas);


Karta & ruchKomputeraPierwszy(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const int wspolrzednaStosuX, const int wspolrzednaStosuY, const int wspolrzedneRekiX[6], sf::RectangleShape maskaKomputera);
Karta & ruchKomputeraDrugi();
Karta & ruchCzlowiekaPierwszy();
Karta & ruchCzlowiekaDrugi();


int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Kolor kolorAtutowy, std::string ktoWygral); //funkcja porównuj¹ca wy³o¿one karty
int dodajMalePunkty(Gracz & komputer, Gracz & czlowiek, int punkty);
void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty); //funkcja pobieraj¹ca karty ze stosu w odpowiedniej kolejnoœci
int rozstrzygnijZwyciestwo(int malePunktyKomputera, int malePunktyCzlowieka);


int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);
	sf::RectangleShape maskaKomputera(sf::Vector2f(130, 177));
	sf::RectangleShape maskaCzlowieka(sf::Vector2f(130, 177));
	sf::RectangleShape maskaStosu(sf::Vector2f(130, 177));

	int timer = 0;
	bool endTimer = false;
	std::thread Timer(threadTick, &timer, &endTimer);
	

	



	Talia talia;
	talia.tasujKarty();

	Kolor kolorAtutowy = talia.odczytajKolorAtutowy();

	Gracz komputer(talia);
	Gracz czlowiek(talia);

	wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
	Sleep(1000);


	wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
	wyswietlKolorAtutowy(window, talia, wspolrzednaKoloruAtutowegoX, wspolrzednaKoloruAtutowegoY);
	window.display();
	Sleep(1000);



	wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
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
			wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
			Sleep(1000);



			if (ktoWygral == "komputer")
			{
				//Ruch komputera - pierwszy ruch nale¿y do komputera

				wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
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

				
				wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
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
				//thread
				wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);


				//Ruch komputera
				kartaKomputera = komputer.dobierzKarte1(kartaCzlowieka);

				wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
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
			wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
			//komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaKomputera);
			//czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaCzlowieka);
			window.display();
			Sleep(1000);

			wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzednaStosuY, wspolrzedneXWylozonychKart, maskaCzlowieka);
			window.display();
			Sleep(1000);


			pobierzKarty(komputer, czlowiek, kartaKomputera, kartaCzlowieka, talia, punkty);

			//wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
			//Sleep(1000);
		}

	
		//druga czêœæ gry - bez stosu kart

		int tablicaKomputera[6] = { 1, 2, 3, 4, 5, 6 };
		int tablicaCzlowieka[6] = { 1, 2, 3, 4, 5, 6 };


		wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
		//zakryjStos(window, maskaStosu, wspolrzednaStosuX, wspolrzednaStosuY);
		//window.display();
		Sleep(1000);
		
		
		

		for (int i = 0; i < rozmiar_reki; i++)
		{
			wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
			Sleep(2000);

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
				//tablicaKomputera[ind] = 0;

				wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
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
				tablicaCzlowieka[indeks] = 0;

				wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
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
				tablicaCzlowieka[indeks] = 0;

				wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
				kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
				czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
				window.display();
				Sleep(1000);

				//ruch komputera
				kartaKomputera = komputer.dobierzKarte2(kartaCzlowieka, tablicaKomputera);
				tablicaKomputera[komputer.znajdzIndeks(kartaKomputera)] = 0;

				wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
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

			//wyswietlStol2(window, komputer, czlowiek, tablicaKomputera, tablicaCzlowieka);
			//Sleep(1000);

		}

		
		endTimer = true;
		Sleep(2000);

		//koniec
		window.clear(sf::Color(30, 91, 6, 1));
		wyswietlInformacjeOZwyciestwie(window, komputer, czlowiek);
		wyswietlInformacjeOCzasieGry(window, timer);
		window.display();
		Sleep(4000);

		endTimer = true;
		Timer.join();

		window.close();
	}

	
	

	
	
	return 0;
	getchar();
}

















void wyswietlStos(sf::RenderWindow & window, const int X, const int Y)
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(X, Y));
	window.draw(sprite);
}

void zakryjStos(sf::RenderWindow & window, sf::RectangleShape maska, const int X, const int Y)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(X, Y);
	window.draw(maska);
}

void wyswietlStol1(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const int X, const int Y)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window, X, Y);
	komputer.wyswietlRekeKomputera1(window);
	czlowiek.wyswietlRekeCzlowieka1(window);
	wyswietlPunktyKomputera(window, komputer);
	wyswietlPunktyCzlowieka(window, czlowiek);
	window.display();
}

void wyswietlStol2(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, int tabKomputera[6], int tabCzlowieka[6])
{
	window.clear(sf::Color(30, 91, 6, 1));
	komputer.wyswietlRekeKomputera2(window, tabKomputera);
	czlowiek.wyswietlRekeCzlowieka2(window, tabCzlowieka);
	wyswietlPunktyKomputera(window, komputer);
	wyswietlPunktyCzlowieka(window, czlowiek);
	window.display();
}

void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia, const int X, const int Y)
{
	talia.pokazKarteAtutowa().wyswietlKarte(window, X, Y);
}


void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska, const int X, const int Y)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(X, Y);
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

 /*Gracz rozstrzygnijZwyciestwo(Gracz komputer, Gracz czlowiek)
{
	if (komputer.odczytajLiczbeMalychPunktow() > czlowiek.odczytajLiczbeMalychPunktow())
		return komputer;
	else
		return czlowiek;
}*/

template <class T>
T rozstrzygnijZwyciestwoT(T a, T b)
{
	if (a.fun() > b.fun())
		return a;
	else
		return b;
}

Karta & ruchKomputeraPierwszy(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek, const int wspolrzednaStosuX, const int wspolrzednaStosuY, const int wspolrzedneRekiX[6], sf::RectangleShape maskaKomputera)
{
	Karta kartaKomputera;

	wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
	kartaKomputera = komputer.wyswietlWylozonaKarteKomputera(window, 0);
	komputer.zakryjPusteMiejsceWReceKomputera(window, 0, wspolrzedneRekiX, maskaKomputera);
	window.display();
	return kartaKomputera;
}

/*int robCos(sf::RenderWindow & window, Karta & kartaCzlowieka, Gracz komputer, Gracz czlowiek, const int wspolrzednaStosuX, const int wpsolrzednaStosuY, int indeks, const int wspolrzednaRekiX[6], sf::RectangleShape maskaCzlowieka)
{
	wyswietlStol1(window, komputer, czlowiek, wspolrzednaStosuX, wspolrzednaStosuY);
	kartaCzlowieka = czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
	czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
	window.display();
	Sleep(1000);
}*/

/*void threadTick(int & timer)
{
	timer++;
	Sleep(1000);
}*/




void wyswietlPunktyKomputera(sf::RenderWindow & window, Gracz komputer)
{
	std::string nazwa = "KOMPUTER";
	std::string punkty = std::to_string(komputer.odczytajLiczbeMalychPunktow());
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		std::cout << "An error occured!" << std::endl;
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(nazwa);
	text1.setCharacterSize(25);
	text1.setPosition(sf::Vector2f(1050, 245));
	text1.setFillColor(sf::Color::White);
	//text1.setStyle(sf::Text::Bold);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(punkty);
	text2.setCharacterSize(25);
	text2.setPosition(sf::Vector2f(1098, 280));
	text2.setFillColor(sf::Color::White);
	//text2.setStyle(sf::Text::Bold);
	
	window.draw(text1);
	window.draw(text2);
}

void wyswietlPunktyCzlowieka(sf::RenderWindow & window, Gracz czlowiek)
{
	std::string nazwa = "TY";
	std::string punkty = std::to_string(czlowiek.odczytajLiczbeMalychPunktow());
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		std::cout << "An error occured!" << std::endl;
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(nazwa);
	text1.setCharacterSize(25);
	text1.setPosition(sf::Vector2f(1093, 350));
	text1.setFillColor(sf::Color::White);
	//text1.setStyle(sf::Text::Bold);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(punkty);
	text2.setCharacterSize(25);
	text2.setPosition(sf::Vector2f(1098, 385));
	text2.setFillColor(sf::Color::White);
	//text2.setStyle(sf::Text::Bold);

	window.draw(text1);
	window.draw(text2);
}

void wyswietlInformacjeOZwyciestwie(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek)
{
	std::string tekst;
	int wygrany = rozstrzygnijZwyciestwo(komputer.odczytajLiczbeMalychPunktow(), czlowiek.odczytajLiczbeMalychPunktow());
	if (wygrany == komputer.odczytajLiczbeMalychPunktow())
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
		std::cout << "An error occured!" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString(tekst);
	text.setCharacterSize(45);
	text.setPosition(sf::Vector2f(200, 300));
	text.setFillColor(sf::Color::White);

	window.draw(text);
}

void wyswietlInformacjeOCzasieGry(sf::RenderWindow & window, int czas)
{
	std::string tekst = "Czas trwania rozgrywki (sekundy): ";
	std::string czasGry = std::to_string(czas);
	sf::Font font;
	if (!font.loadFromFile("VCR_OSD_MONO_1.001.ttf"))
	{
		std::cout << "An error occured!" << std::endl;
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString(tekst);
	text1.setCharacterSize(45);
	text1.setPosition(sf::Vector2f(100, 400));
	text1.setFillColor(sf::Color::White);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(czasGry);
	text2.setCharacterSize(45);
	text2.setPosition(sf::Vector2f(900, 400));
	text2.setFillColor(sf::Color::White);

	window.draw(text1);
	window.draw(text2);
}