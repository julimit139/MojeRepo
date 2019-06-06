#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"

sf::RenderWindow & wyswietlStos(sf::RenderWindow & window);
void wyswietlStol(sf::RenderWindow & window, Reka rekaCzlowieka, Reka rekaKomputera);
int wybierzKarte(sf::RenderWindow & window, int x, int y);
void wyswietlRekeCzlowieka(sf::RenderWindow & window, Reka rekaCzlowieka);

int main()
{
	Talia talia;
	talia.tasujKarty();

	Reka rekaCzlowieka(talia);
	Reka rekaKomputera(talia);

	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			wyswietlStol(window, rekaCzlowieka, rekaKomputera);

			/*window.clear(sf::Color(30, 91, 6, 1));
			Karta mojaKarta(dama, kier, "dama_kier.jpg");
			sf::Texture texture;
			if (!texture.loadFromFile("dama_kier.jpg"))
			{
				texture.loadFromFile("joker.jpg");
			}
			sf::Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition(sf::Vector2f(200, 200));
			window.draw(sprite);
			window.display();*/


			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
				break;
			}

			case sf::Event::MouseButtonPressed:
			{
				std::cout << "Mouse button has been pressed" << std::endl;

				switch (event.key.code)
				{
					case sf::Mouse::Left:
					{
						int x = sf::Mouse::getPosition(window).x;
						int y = sf::Mouse::getPosition(window).y;
						//auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
						//auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
						
						wybierzKarte(window, x, y);


						/*for (int i = 0; i < 6; i++)
						{
							std::cout << rekaCzlowieka[i].sprite.getPosition().x << ", " << rekaCzlowieka[i].sprite.getPosition().y << std::endl;

							if (rekaCzlowieka[i].sprite.getGlobalBounds().contains(translated_pos))
							{
								std::cout << rekaCzlowieka[i].nazwaObrazu << std::endl;
							}
						}*/
		
						/*if (sprite.getGlobalBounds().contains(translated_pos))
						{
							std::cout << "Aha!"<< std::endl;
						}*/

						break;
					}
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				std::cout << "Mouse button has been released" << std::endl;
				
				switch (event.key.code)
				{
					case sf::Mouse::Right:
					{
						std::cout << "Right key has been released" << std::endl;
						break;
					}
				}
			}


			}
			

				
		}
	}

	
	
	std::cout << "Ciastko!" << std::endl;

	

	return 0;
	getchar();
}





sf::RenderWindow & wyswietlStos(sf::RenderWindow & window)
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
	return window;
}

void wyswietlStol(sf::RenderWindow & window, Reka rekaCzlowieka, Reka rekaKomputera)
{
	window.clear(sf::Color(30, 91, 6, 1));
	wyswietlStos(window);
	rekaCzlowieka.wyswietlRekeCzlowieka(window);
	rekaKomputera.wyswietlRekeKomputera(window);
	window.display();
}

int wybierzKarte(sf::RenderWindow & window, int x, int y)
{
	int indeks = 7;
	if (y >= 470 && y <= 640)
	{
		if (x >= 144 && x <= 267)
		{
			indeks = 0;
		}
		else if (x >= 294 && x <= 417)
		{
			indeks = 1;
		}
		else if (x >= 444 && x <= 567)
		{
			indeks = 2;
		}
		else if (x >= 594 && x <= 717)
		{
			indeks = 3;
		}
		else if (x >= 744 && x <= 867)
		{
			indeks = 4;
		}
		else if (x >= 894 && x <= 1017)
		{
			indeks = 5;
		}
		std::cout << indeks << std::endl;
		return indeks;
	}

	






}


