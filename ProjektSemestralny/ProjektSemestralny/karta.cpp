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

void Karta::zmienWlascowsciKarty(Karta nowa)
{
	this->kolor = nowa.odczytajKolor();
	this->wartosc = nowa.odczytajWartosc();
	this->nazwaObrazu = nowa.odczytajNazweObrazu();
}

void Karta::wyswietlKarte(sf::RenderWindow & window, int x, int y)
{
	sf::Texture texture;
	if (!texture.loadFromFile(this->odczytajNazweObrazu()))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	window.draw(sprite);
}