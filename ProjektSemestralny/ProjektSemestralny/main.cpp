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

	sf::RenderWindow window(sf::VideoMode(1200, 650), "My window", sf::Style::Default);

	wyswietlStol(window, rekaCzlowieka, rekaKomputera);
	


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

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)

				window.close();
		}
	}
}