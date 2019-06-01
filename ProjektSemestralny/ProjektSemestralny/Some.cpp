#include "Some.h"

void foo()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "My window", sf::Style::Default);
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	sf::Texture texture;
	if (!texture.loadFromFile("joker.jpg"))
	{
		std::cout << "Couldn't load an image from file\n";
	}

	sf::Sprite sprite1;
	sprite1.setTexture(texture);
	sprite1.setPosition(sf::Vector2f(144.f, 20.f));

	sf::Sprite sprite2;
	sprite2.setTexture(texture);
	sprite2.setPosition(sf::Vector2f(302.f, 20.f));

	sf::Sprite sprite3;
	sprite3.setTexture(texture);
	sprite3.setPosition(sf::Vector2f(460.f, 20.f));

	sf::Sprite sprite4;
	sprite4.setTexture(texture);
	sprite4.setPosition(sf::Vector2f(618.f, 20.f));

	sf::Sprite sprite5;
	sprite5.setTexture(texture);
	sprite5.setPosition(sf::Vector2f(776.f, 20.f));

	sf::Sprite sprite6;
	sprite6.setTexture(texture);
	sprite6.setPosition(sf::Vector2f(934.f, 20.f));

	sf::Sprite sprite7;
	sprite7.setTexture(texture);
	sprite7.setPosition(sf::Vector2f(144.f, 470.f));

	sf::Sprite sprite8;
	sprite8.setTexture(texture);
	sprite8.setPosition(sf::Vector2f(302.f, 470.f));

	sf::Sprite sprite9;
	sprite9.setTexture(texture);
	sprite9.setPosition(sf::Vector2f(460.f, 470.f));

	sf::Sprite sprite10;
	sprite10.setTexture(texture);
	sprite10.setPosition(sf::Vector2f(618.f, 470.f));

	sf::Sprite sprite11;
	sprite11.setTexture(texture);
	sprite11.setPosition(sf::Vector2f(776.f, 470.f));

	sf::Sprite sprite12;
	sprite12.setTexture(texture);
	sprite12.setPosition(sf::Vector2f(934.f, 470.f));

	sf::Texture texture2;
	texture2.loadFromFile("tyl_karty.jpg");
	sf::Sprite sprite13;
	sprite13.setTexture(texture2);
	sprite13.setPosition(sf::Vector2f(79.f, 245.f));

	window.clear(sf::Color(30, 91, 6, 1));

	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
	window.draw(sprite6);
	window.draw(sprite7);
	window.draw(sprite8);
	window.draw(sprite9);
	window.draw(sprite10);
	window.draw(sprite11);
	window.draw(sprite12);
	window.draw(sprite13);

	window.display();



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{			if (event.type == sf::Event::Closed)

				window.close();
		}
	}

}