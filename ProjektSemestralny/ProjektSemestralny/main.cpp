#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "gracz.h"

void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia);
void wyswietlStos(sf::RenderWindow & window);
void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek);


int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);

	Talia talia;
	talia.tasujKarty();

	Gracz komputer(talia);
	Gracz czlowiek(talia);


	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window);
	komputer.wyswietlRekeKomputera(window);
	czlowiek.wyswietlRekeCzlowieka(window);
	wyswietlKolorAtutowy(window, talia);
	window.display();

	
	
	std::string ktoWygral = "komputer";


	while (window.isOpen())
	{
		//pierwszy ruch nale¿y do komputera
		if (ktoWygral == "komputer")
		{
			komputer.wyswietlWylozonaKarteKomputera(window, 0);
			window.display();
			komputer.zakryjPusteMiejsceWReceKomputera(window, 0, wspolrzedneRekiX);
			window.display();



		}
		else if (ktoWygral == "czlowiek")
		{




		}
		
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{






		

			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				std::cout << "Mouse button has been pressed" << std::endl;

				switch (event.key.code)
				{
					case sf::Mouse::Left:
					{
						int x = sf::Mouse::getPosition(window).x;
						int y = sf::Mouse::getPosition(window).y;
						
						int indeks = czlowiek.wybierzKarte(window, x, y);

						//czlowiek.wyswietlWylozonaKarteCzlowieka(window, indeks);
						

						//czlowiek.pobierzKarte(window, x, y, talia, indeks);




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

	
	
	std::cout << "Ciastko!" << std::endl;

	

	return 0;
	getchar();
}



void wyswietlKolorAtutowy(sf::RenderWindow & window, Talia talia)
{
	talia.pokazKarteAtutowa().wyswietlKarte(window, 519, 245);
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




