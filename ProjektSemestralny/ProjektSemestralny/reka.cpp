#include "reka.h"

Reka::Reka(Talia & talia)
{
	for (int i = 0; i < rozmiarReki; i++)
	{
		reka.push_back(talia.zdejmijKarte());
	}
	kolorAtutowy = talia.odczytajKolorAtutowy();
}

void Reka::pobierzKarte(Talia & talia, int indeks)
{
	reka[indeks] = talia.zdejmijKarte();
}

Karta & Reka::wezKarteSpodIndeksu1(int indeks)
{
	return reka[indeks];
}

Karta & Reka::wezKarteSpodIndeksu2(int indeks, int * tab)
{
	tab[indeks] = 0;
	return reka[indeks];
}

int Reka::znajdzIndeks(Karta karta)
{
	int indeks = 0;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		if (((*it).odczytajWartosc() == karta.odczytajWartosc()) && ((*it).odczytajKolor() == karta.odczytajKolor()))
		{
			break;
		}
		indeks += 1;
	}
	return indeks;
}

Karta Reka::dobierzKarte1(Karta kartaWylozona)
{
	Karta * kartaDobrana = NULL;
	if (kartaWylozona.odczytajKolor() == kolorAtutowy)
	{
		for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
		{
			if ((*it).odczytajKolor() == kolorAtutowy)
			{
				if ((*it).odczytajWartosc() > kartaWylozona.odczytajWartosc())
				{
					if (kartaDobrana == NULL)
					{
						kartaDobrana = &(*it);
					}
					if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
					{
						kartaDobrana = &(*it);
					}
				}
			}
		}
		if (kartaDobrana == NULL)
		{
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if ((*it).odczytajKolor() != kolorAtutowy)
				{
					if (kartaDobrana == NULL)
					{
						kartaDobrana = &(*it);
					}
					if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
					{
						kartaDobrana = &(*it);
					}
				}
			}
		}
	}
	else
	{
		for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
		{
			if ((*it).odczytajKolor() == kartaWylozona.odczytajKolor())
			{
				if ((*it).odczytajWartosc() > kartaWylozona.odczytajWartosc())
				{
					if (kartaDobrana == NULL)
					{
						kartaDobrana = &(*it);
					}
					if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
					{
						kartaDobrana = &(*it);
					}
				}
			}
		}
		if (kartaDobrana == NULL)
		{
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if ((*it).odczytajKolor() == kolorAtutowy)
				{
					if (kartaDobrana == NULL)
					{
						kartaDobrana = &(*it);
					}
					if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
					{
						kartaDobrana = &(*it);
					}
				}
			}
		}
		if (kartaDobrana == NULL)
		{
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (((*it).odczytajKolor() != kartaWylozona.odczytajKolor()) && ((*it).odczytajKolor() != kolorAtutowy))
				{
					if (kartaDobrana == NULL)
					{
						kartaDobrana = &(*it);
					}
					if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
					{
						kartaDobrana = &(*it);
					}
				}
			}
		}
	}
	return *kartaDobrana;
}

Karta Reka::dobierzKarte2(Karta kartaWylozona, int * tab)
{
	Karta * kartaDobrana = NULL;
	int indeks = 0;
	if (kartaWylozona.odczytajKolor() == kolorAtutowy)
	{
		for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
		{
			if (tab[indeks] != 0)
			{
				if ((*it).odczytajKolor() == kolorAtutowy)
				{
					if ((*it).odczytajWartosc() > kartaWylozona.odczytajWartosc())
					{
						if (kartaDobrana == NULL)
						{
							kartaDobrana = &(*it);
						}
						if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
						{
							kartaDobrana = &(*it);
						}
					}
				}
			}
			indeks += 1;
		}
		if (kartaDobrana == NULL)
		{
			indeks = 0;
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (tab[indeks] != 0)
				{
					if ((*it).odczytajKolor() == kolorAtutowy)
					{
						if ((*it).odczytajWartosc() < kartaWylozona.odczytajWartosc())
						{
							if (kartaDobrana == NULL)
							{
								kartaDobrana = &(*it);
							}
							if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
							{
								kartaDobrana = &(*it);
							}
						}
					}
				}
				indeks += 1;
			}
		}
		if (kartaDobrana == NULL)
		{
			indeks = 0;
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (tab[indeks] != 0)
				{
					if ((*it).odczytajKolor() != kolorAtutowy)
					{
						if (kartaDobrana == NULL)
						{
							kartaDobrana = &(*it);
						}
						if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
						{
							kartaDobrana = &(*it);
						}
					}
				}
				indeks += 1;
			}
		}
	}
	else
	{
		for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
		{
			if (tab[indeks] != 0)
			{
				if ((*it).odczytajKolor() == kartaWylozona.odczytajKolor())
				{
					if ((*it).odczytajWartosc() > kartaWylozona.odczytajWartosc())
					{
						if (kartaDobrana == NULL)
						{
							kartaDobrana = &(*it);
						}
						if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
						{
							kartaDobrana = &(*it);
						}
					}
				}
			}
			indeks += 1;
		}
		if (kartaDobrana == NULL)
		{
			indeks = 0;
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (tab[indeks] != 0)
				{
					if ((*it).odczytajKolor() == kartaWylozona.odczytajKolor())
					{
						if ((*it).odczytajWartosc() < kartaWylozona.odczytajWartosc())
						{
							if (kartaDobrana == NULL)
							{
								kartaDobrana = &(*it);
							}
							if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
							{
								kartaDobrana = &(*it);
							}
						}
					}
				}
				indeks += 1;
			}
		}
		if (kartaDobrana == NULL)
		{
			indeks = 0;
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (tab[indeks] != 0)
				{
					if ((*it).odczytajKolor() == kolorAtutowy)
					{
						if (kartaDobrana == NULL)
						{
							kartaDobrana = &(*it);
						}
						if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
						{
							kartaDobrana = &(*it);
						}
					}
				}
				indeks += 1;
			}
		}
		if (kartaDobrana == NULL)
		{
			indeks = 0;
			for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
			{
				if (tab[indeks] != 0)
				{
					if (((*it).odczytajKolor() != kartaWylozona.odczytajKolor()) && ((*it).odczytajKolor() != kolorAtutowy))
					{
						if (kartaDobrana == NULL)
						{
							kartaDobrana = &(*it);
						}
						if ((kartaDobrana != NULL) && ((*it).odczytajWartosc() < kartaDobrana->odczytajWartosc()))
						{
							kartaDobrana = &(*it);
						}
					}
				}
				indeks += 1;
			}
		}
	}
	return *kartaDobrana;
}

Karta & Reka::operator[](int indeks)
{
	return this->reka[indeks];
}

void Reka::wyswietlRekeKomputera1(sf::RenderWindow & window, const float x[6], const float y[2])
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	int indeks = 0;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		sprite.setPosition(sf::Vector2f(x[indeks], y[0]));
		window.draw(sprite);
		indeks++;
	}
}

void Reka::wyswietlRekeCzlowieka1(sf::RenderWindow & window, const float x[6], const float y[2])
{
	int indeks = 0;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		(*it).wyswietlKarte(window, x[indeks], y[1]);
		indeks++;
	}
}

void Reka::wyswietlRekeKomputera2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2])
{
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	for (int i = 0; i < rozmiarReki; i++)
	{
		if (tab[i] != 0)
		{
			sprite.setPosition(sf::Vector2f(x[i], y[0]));
			window.draw(sprite);
		}
	}
}

void Reka::wyswietlRekeCzlowieka2(sf::RenderWindow & window, int tab[6], const float x[6], const float y[2])
{
	int i = 0;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		if (tab[i] != 0)
		{
			(*it).wyswietlKarte(window, x[i], y[1]);
		}
		i++;
	}
}
