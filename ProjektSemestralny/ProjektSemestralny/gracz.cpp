#include "gracz.h"

Gracz::Gracz(Talia & talia) : reka(talia)
{
	zbiorLew = new Lewa[12];
}

void Gracz::pobierzKarte(Talia & talia, int indeks)
{
	reka.pobierzKarte(talia, indeks);
}

Karta & Gracz::wezKarteSpodIndeksu1(int indeks)
{
	return reka.wezKarteSpodIndeksu1(indeks);
}

Karta & Gracz::wezKarteSpodIndeksu2(int indeks, int * tab)
{
	return reka.wezKarteSpodIndeksu2(indeks, tab);
}

int Gracz::znajdzIndeks(Karta karta)
{
	return reka.znajdzIndeks(karta);
}

Karta Gracz::dobierzKarte1(Karta kartaWylozona)
{
	return reka.dobierzKarte1(kartaWylozona);
}

Karta Gracz::dobierzKarte2(Karta kartaWylozona, int * tab)
{
	return reka.dobierzKarte2(kartaWylozona, tab);
}

int Gracz::dodajPunkty(int punkty)
{
	liczbaPunktow += punkty;
	return liczbaPunktow;
}

int Gracz::odczytajLiczbePunktow()
{
	return liczbaPunktow;
}

void Gracz::dodajLewe(Karta kartaKomputera, Karta kartaCzlowieka)
{
	zbiorLew[licznikZebranychLew] = Lewa(kartaKomputera, kartaCzlowieka);
	licznikZebranychLew += 1;
}

int Gracz::wybierzKarte(sf::RenderWindow & window, int x, int y, const float X[6], const float Y[2], const float w, const float s)
{
	int indeks = 7;
	if (y >= Y[1] && y <= (Y[1] + w))
	{
		if (x >= X[0] && x <= (X[0] + s))
		{
			indeks = 0;
		}
		else if (x >= X[1] && x <= (X[1] + s))
		{
			indeks = 1;
		}
		else if (x >= X[2] && x <= (X[2] + s))
		{
			indeks = 2;
		}
		else if (x >= X[3] && x <= (X[3] + s))
		{
			indeks = 3;
		}
		else if (x >= X[4] && x <= (X[4] + s))
		{
			indeks = 4;
		}
		else if (x >= X[5] && x <= (X[5] + s))
		{
			indeks = 5;
		}
	}
	return indeks;
}

void Gracz::wyswietlRekeKomputera1(sf::RenderWindow & window, const float x[6], const float y[2])
{
	reka.wyswietlRekeKomputera1(window, x, y);
}

void Gracz::wyswietlRekeCzlowieka1(sf::RenderWindow & window, const float x[6], const float y[2])
{
	reka.wyswietlRekeCzlowieka1(window, x, y);
}

void Gracz::wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2])
{
	reka.wyswietlRekeKomputera2(window, tab, x, y);
}

void Gracz::wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2])
{
	reka.wyswietlRekeCzlowieka2(window, tab, x, y);
}

Karta & Gracz::wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks, const float x, const float y)
{
	reka[indeks].wyswietlKarte(window, x, y);
	return reka[indeks];
}

Karta & Gracz::wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks, const float x, const float y)
{
	reka[indeks].wyswietlKarte(window, x, y);
	return reka[indeks];
}

void Gracz::zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x[indeks], y[0]);
	window.draw(maska);
}

void Gracz::zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const float x[6], const float y[2], sf::RectangleShape & maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x[indeks], y[1]);
	window.draw(maska);
}

void Gracz::zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x[0], y);
	window.draw(maska);
}

void Gracz::zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const float x[2], const float y, sf::RectangleShape maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(x[1], y);
	window.draw(maska);
}

void Gracz::wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta kartaKomputera, const float x, const float y[2])
{
	kartaKomputera.wyswietlKarte(window, x, y[0]);
}

void Gracz::wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta kartaCzlowieka, const float x, const float y[2])
{
	kartaCzlowieka.wyswietlKarte(window, x, y[1]);
}

/*void Gracz::wyswietlZbiorLew()
{
	for (int i = 0; i < licznikZebranychLew; i++)
	{
		std::cout << "Lewa " << i + 1 << ":\n" << zbiorLew[i] << std::endl;

	}
}*/