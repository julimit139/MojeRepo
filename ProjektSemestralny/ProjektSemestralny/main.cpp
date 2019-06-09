#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "gracz.h"


void wyswietlStos(sf::RenderWindow & window);
void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek);
void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia);
void zakryjKolorAtutowy(sf::RenderWindow & window, sf::RectangleShape maska);


int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Talia talia, std::string ktoWygral); //funkcja por�wnuj�ca wy�o�one karty
int dodajMalePunkty(Gracz & komputer, Gracz & czlowiek, int punkty);
void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty); //funkcja pobieraj�ca karty ze stosu w odpowiedniej kolejno�ci



int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);
	sf::RectangleShape maskaKomputera(sf::Vector2f(123, 170));
	sf::RectangleShape maskaCzlowieka(sf::Vector2f(123, 170));

	Talia talia;
	talia.tasujKarty();

	Gracz komputer(talia);
	Gracz czlowiek(talia);

	wyswietlStol(window, komputer, czlowiek);
	Sleep(2000);


	wyswietlStol(window, komputer, czlowiek);
	wyswietlKolorAtutowy(window, talia);
	window.display();
	Sleep(2000);



	wyswietlStol(window, komputer, czlowiek);
	zakryjKolorAtutowy(window, maskaKomputera);
	window.display();
	Sleep(2000);

	
	
	std::string ktoWygral = "komputer";
	Karta kartaKomputera;
	Karta kartaCzlowieka;


	while (window.isOpen())
	{
		//Ruch komputera - pierwszy ruch nale�y do komputera
		if (ktoWygral == "komputer")
		{
			wyswietlStol(window, komputer, czlowiek);
			komputer.wyswietlWylozonaKarteKomputera(window, 0);
			komputer.zakryjPusteMiejsceWReceKomputera(window, 0, wspolrzedneRekiX, maskaKomputera);
			window.display();
			Sleep(2000);

		
			
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
			czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
			czlowiek.zakryjPusteMiejsceWReceCzlowieka(window, indeks, wspolrzedneRekiX, maskaCzlowieka);
			window.display();
			Sleep(2000);

		}
		else if (ktoWygral == "czlowiek")
		{
			//Ruch gracza

			//Ruch komputera


		}
		
		
		int punkty = porownajKarty(kartaKomputera, kartaCzlowieka, talia, ktoWygral);
		if (punkty < 0)
		{
			ktoWygral = "komputer";
		}
		else
		{
			ktoWygral = "czlowiek";
		}
		dodajMalePunkty(komputer, czlowiek, punkty);
		pobierzKarty(komputer, czlowiek, kartaKomputera, kartaCzlowieka, talia, punkty);


		
		
			
			

			
			

				
		
	}

	
	


	

	return 0;
	getchar();
}

















void wyswietlStos(sf::RenderWindow & window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(79, 245));
	window.draw(sprite);
}

void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window);
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
	maska.setFillColor(sf::Color(60, 0, 90));
	maska.setPosition(519, 245);
	window.draw(maska);
	window.display();
}




int porownajKarty(Karta kartaKomputera, Karta kartaCzlowieka, Talia talia, std::string ktoWygral)
{
	int punkty = 0;
	if (kartaKomputera.odczytajKolor() == talia.odczytajKolorAtutowy())
	{
		if (kartaCzlowieka.odczytajKolor() == talia.odczytajKolorAtutowy())
		{
			if (kartaKomputera.odczytajWartosc() > kartaCzlowieka.odczytajWartosc())
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz�owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
		}
		else
		{
			punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
			punkty -= kartaCzlowieka.odczytajWartosc();
		}

	}
	if (kartaKomputera.odczytajKolor() != talia.odczytajKolorAtutowy())
	{
		if (kartaCzlowieka.odczytajKolor() != talia.odczytajKolorAtutowy())
		{
			if ((kartaKomputera.odczytajWartosc() == kartaCzlowieka.odczytajWartosc()) && (ktoWygral == "komputer"))
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else if ((kartaKomputera.odczytajWartosc() == kartaCzlowieka.odczytajWartosc()) && (ktoWygral == "czlowiek"))
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz�owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
			else if (kartaKomputera.odczytajWartosc() > kartaCzlowieka.odczytajWartosc())
			{
				punkty -= kartaKomputera.odczytajWartosc(); //punkty na minusie -> punkty dla komputera
				punkty -= kartaCzlowieka.odczytajWartosc();
			}
			else
			{
				punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz�owieka
				punkty += kartaCzlowieka.odczytajWartosc();
			}
		}
		else
		{
			punkty += kartaKomputera.odczytajWartosc(); //punkty na plusie -> punkty dla cz�owieka
			punkty += kartaCzlowieka.odczytajWartosc();
		}
	}
	return punkty;
}

int dodajMalePunkty(Gracz & komputer, Gracz & czlowiek, int punkty) //dodaje punkty odpowiedniemu graczowi; je�eli punkty < 0, to dodaje komputerowi, w przeciwnym wypadku cz�owiekowi
{
	if (punkty < 0)
	{
		punkty = -punkty; //liczb� uzyskanych punkt�w zamienia na przeciwn�, dodatni� i dodaje do liczby ma�ych punkt�w komputera
		komputer.dodajMalePunkty(punkty);
		return punkty;
	}
	else
	{
		czlowiek.dodajMalePunkty(punkty); //dodaje punkty do liczby ma�ych punkt�w cz�owieka
		return punkty;
	}
}

void pobierzKarty(Gracz & komputer, Gracz & czlowiek, Karta kartaKomputera, Karta kartaCzlowieka, Talia & talia, int punkty) //pobiera karty poczynaj�c od tego gracza, kt�ry wzi�� lew�
{
	if (punkty < 0)
	{

		komputer.pobierzKarte(talia, komputer.znajdzIndeks(kartaKomputera)); //lew� wzi�� komputer, wi�c najpierw pobiera si� karta dla niego, potem dla cz�owieka
		czlowiek.pobierzKarte(talia, czlowiek.znajdzIndeks(kartaCzlowieka));
	}
	else
	{
		czlowiek.pobierzKarte(talia, czlowiek.znajdzIndeks(kartaCzlowieka)); //lew� wzi�� cz�owiek, wi�c najpierw pobiera si� karta dla niego, potem dla komputera
		komputer.pobierzKarte(talia, komputer.znajdzIndeks(kartaKomputera));
	}
}