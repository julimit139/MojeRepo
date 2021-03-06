#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "My window", sf::Style::Default);
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	sf::Texture texture;
	if (!texture.loadFromFile("heart_king.png"))
	{
		std::cout << "Couldn't load an image from file\n";
	}

	sf::Sprite sprite1;
	sprite1.setTexture(texture);
	sprite1.setPosition(sf::Vector2f(20.f, 50.f));

	sf::Sprite sprite2;
	sprite2.setTexture(texture);
	sprite2.setPosition(sf::Vector2f(150.f, 50.f));

	sf::Sprite sprite3;
	sprite3.setTexture(texture);
	sprite3.setPosition(sf::Vector2f(280.f, 50.f));

	sf::Sprite sprite4;
	sprite4.setTexture(texture);
	sprite4.setPosition(sf::Vector2f(410.f, 50.f));

	sf::Sprite sprite5;
	sprite5.setTexture(texture);
	sprite5.setPosition(sf::Vector2f(540.f, 50.f));

	sf::Sprite sprite6;
	sprite6.setTexture(texture);
	sprite6.setPosition(sf::Vector2f(670.f, 50.f));

	window.clear(sf::Color(30,91,6,1));

	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
	window.draw(sprite6);

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

	return 0;
}