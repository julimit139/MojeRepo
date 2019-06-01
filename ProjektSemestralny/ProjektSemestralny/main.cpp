#include <iostream>
#include "stale.h"
#include "karta.h"
#include "talia.h"
#include "reka.h"

sf::RenderWindow & wyswietlStos(sf::RenderWindow & window);
void wyswietlStol(sf::RenderWindow & window, Reka rekaCzlowieka, Reka rekaKomputera);

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
				break;
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