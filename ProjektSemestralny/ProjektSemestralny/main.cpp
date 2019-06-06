#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"
#include "gracz.h"

void wyswietlStos(sf::RenderWindow & window);
void wyswietlStol(sf::RenderWindow & window, Gracz komputer, Gracz czlowiek);


int main()
{
	Talia talia;
	talia.tasujKarty();

	Gracz komputer(talia);
	Gracz czlowiek(talia);
	

	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			wyswietlStol(window, komputer, czlowiek);

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
						
						czlowiek.wybierzKarte(window, x, y);

						break;
					}
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				std::cout << "Mouse button has been released" << std::endl;
				break;
			}


			}
			

				
		}
	}

	
	
	std::cout << "Ciastko!" << std::endl;

	

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




