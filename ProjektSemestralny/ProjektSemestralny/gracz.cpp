#include "gracz.h"

Gracz::Gracz(Talia & talia) : reka(talia)
{
	zbiorLew = new Lewa[12];
	licznikZebranychLew = 0;
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

int Gracz::dodajMalePunkty(int punkty)
{
	malePunkty += punkty;
	return malePunkty;
}

int Gracz::odczytajLiczbeMalychPunktow()
{
	return malePunkty;
}

void Gracz::dodajLewe(Karta karta1, Karta karta2)
{
	zbiorLew[licznikZebranychLew] = Lewa(karta1, karta2);
	licznikZebranychLew++;
}

int Gracz::wybierzKarte(sf::RenderWindow & window, int x, int y)
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
	}
	std::cout << indeks << std::endl;
	return indeks;
}

void Gracz::wyswietlRekeKomputera1(sf::RenderWindow & window)
{
	reka.wyswietlRekeKomputera1(window);
}

void Gracz::wyswietlRekeCzlowieka1(sf::RenderWindow & window)
{
	reka.wyswietlRekeCzlowieka1(window);
}

void Gracz::wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6])
{
	reka.wyswietlRekeKomputera2(window, tab);
}

void Gracz::wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6])
{
	reka.wyswietlRekeCzlowieka2(window, tab);
}

Karta & Gracz::wyswietlWylozonaKarteKomputera(sf::RenderWindow & window, int indeks)
{
	reka[indeks].wyswietlKarte(window, 444, 245);
	return reka[indeks];
}

Karta & Gracz::wyswietlWylozonaKarteCzlowieka(sf::RenderWindow & window, int indeks)
{
	reka[indeks].wyswietlKarte(window, 594, 245);
	return reka[indeks];
}

void Gracz::zakryjPusteMiejsceWReceKomputera(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(tabX[indeks], 20);
	window.draw(maska);
}

void Gracz::zakryjPusteMiejsceWReceCzlowieka(sf::RenderWindow & window, int indeks, const int tabX[6], sf::RectangleShape & maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(tabX[indeks], 470);
	window.draw(maska);
}

void Gracz::zakryjWyswietlonaKarteKomputera(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(tabX[0], wspolerzednaStosuY);
	window.draw(maska);
}

void Gracz::zakryjWyswietlonaKarteCzlowieka(sf::RenderWindow & window, const int wspolerzednaStosuY, const int tabX[2], sf::RectangleShape maska)
{
	maska.setFillColor(sf::Color(30, 91, 6));
	maska.setPosition(tabX[1], wspolerzednaStosuY);
	window.draw(maska);
}

void Gracz::wyswietlWygranaLeweKomputera(sf::RenderWindow & window, Karta karta)
{
	karta.wyswietlKarte(window, 1044, 20);
}

void Gracz::wyswietlWygranaLeweCzlowieka(sf::RenderWindow & window, Karta karta)
{
	karta.wyswietlKarte(window, 1044, 470);
}


/*Karta Gracz::jakaKarta(int indeks)
{
	return reka[indeks];
}*/

/*int Gracz::dodajDuzePunkty(int punkty)
{
	duzePunkty += punkty;
	return duzePunkty;
}*/

/*void Gracz::wyswietlZbiorLew()
{
	for (int i = 0; i < licznikZebranychLew; i++)
	{
		std::cout << "Lewa " << i + 1 << ":\n" << zbiorLew[i] << std::endl;

	}
}*/

/*int Gracz::sprawdz_warunek_podmiany()
{
	return reka.sprawdz_warunek_podmiany();
}*/

/*void Gracz::podmien(Talia & talia, int indeks)
{
	reka.podmien(talia, indeks);
}*/

/*int Gracz::sprawdz_meldunek()
{
	return reka.sprawdz_meldunek();
}*/