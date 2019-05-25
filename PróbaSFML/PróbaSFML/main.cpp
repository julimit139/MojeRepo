#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				std::cout << "new width: " << event.size.width << std::endl;
				std::cout << "new height: " << event.size.height << std::endl;
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
				std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			}
			if (event.type == sf::Event::MouseEntered)
				std::cout << "the mouse cursor has entered the window" << std::endl;

			if (event.type == sf::Event::MouseLeft)
				std::cout << "the mouse cursor has left the window" << std::endl;
		}

		/*window.clear();
		window.draw(shape);
		window.display();*/
	}

	return 0;
}