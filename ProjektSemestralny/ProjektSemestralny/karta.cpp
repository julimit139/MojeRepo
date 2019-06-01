#include "karta.h"

Karta::Karta()
{
	this->wartosc = dziewiatka;
	this->kolor = pik;
}

Karta::Karta(Wartosc w, Kolor k, std::string n)
{
	wartosc = w;
	kolor = k;
	nazwaObrazu = n;
	/*if (!tekstura.loadFromFile(nazwaObrazu))
	{
		tekstura.loadFromFile("joker.png");
	}
	obraz.setTexture(tekstura, true);*/
}

Wartosc & Karta::odczytajWartosc()
{
	return this->wartosc;
}

Kolor & Karta::odczytajKolor()
{
	return this->kolor;
}

std::string Karta::odczytajNazweObrazu()
{
	return this->nazwaObrazu;
}

void Karta::wyswietlKarte(sf::RenderWindow & window)
{
	sf::Texture texture;
	if (!texture.loadFromFile(this->odczytajNazweObrazu()))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	//sprite.setPosition(sf::Vector2f(144.f, 20.f));
	window.clear(sf::Color(30, 91, 6, 1));
	window.draw(sprite);
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

std::ostream & operator << (std::ostream & wypisz, Karta karta)
{
	switch (karta.odczytajWartosc())
	{
	case dziewiatka:
		wypisz << "9 ";
		break;
	case walet:
		wypisz << "W ";
		break;
	case dama:
		wypisz << "D ";
		break;
	case krol:
		wypisz << "K ";
		break;
	case dziesiatka:
		wypisz << "10 ";
		break;
	case as:
		wypisz << "A ";
		break;
	}
	switch (karta.odczytajKolor())
	{
	case pik:
		wypisz << "pik\n";
		break;
	case kier:
		wypisz << "kier\n";
		break;
	case karo:
		wypisz << "karo\n";
		break;
	case trefl:
		wypisz << "trefl\n";
		break;
	}
	return wypisz;
}