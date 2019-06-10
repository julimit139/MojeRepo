#include "reka.h"

Reka::Reka(Talia & talia)
{
	for (int i = 0; i < rozmiar_reki; i++)
	{
		reka.push_back(talia.zdejmijKarte());
	}
	kolorAtutowy = talia.odczytajKolorAtutowy();
}

void Reka::pobierzKarte(Talia & talia, int indeks)
{
	reka[indeks] = talia.zdejmijKarte();
	//reka[indeks].zmienWlascowsciKarty(talia.zdejmijKarte());
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

void Reka::wyswietlRekeKomputera(sf::RenderWindow & window)
{
	int x = 144;
	int y = 20;
	sf::Texture texture;
	if (!texture.loadFromFile("tyl_karty.jpg"))
	{
		texture.loadFromFile("joker.jpg");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		sprite.setPosition(sf::Vector2f(x, y));
		window.draw(sprite);
		x += 150;
	}
}

void Reka::wyswietlRekeCzlowieka(sf::RenderWindow & window)
{
	int x = 144;
	int y = 470;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		(*it).wyswietlKarte(window, x, y);
		x += 150;
	}
}







/*void Reka::wyswietlAktualnaReke()
{
	int indeks = 0;
	std::cout << "Twoja aktualna reka to:\n\n";
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		std::cout << (indeks + 1) << ". " << (*it) << std::endl;
		indeks += 1;
	}
}

void Reka::wyswietlAktualnaRekePomniejszona(int * tab)
{
	int indeks = 0;
	std::cout << "Twoja aktualna reka to:\n\n";
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		if (tab[indeks] == 0)
		{
			std::cout << (indeks + 1) << ". ---\n";
		}
		else
		{
			std::cout << (indeks + 1) << ". " << (*it) << std::endl;
		}
		indeks += 1;
	}
}

int Reka::sprawdzWarunekPodmiany()
{
	bool podmianaBool = false;
	int podmianaInt = 0;
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		if (((*it).odczytajWartosc() == dziewiatka) && ((*it).odczytajKolor() == kolorAtutowy))
		{
			podmianaBool = true;
			break;
		}
		podmianaInt += 1;
	}
	if (podmianaBool == false)
	{
		podmianaInt = 7;
	}
	return podmianaInt;

}

void Reka::podmien(Talia & talia, int indeks)
{
	Karta tmp = reka[indeks];
	Wartosc w = talia.odczytajWartoscOdkrytejKartyAtutowej();
	//std::string s = talia.begin()->odczytajNazweObrazu();
	//reka[indeks] = Karta(w, kolorAtutowy);
	talia.podmienKarteWTalii(tmp);
}

int Reka::sprawdzMeldunek()
{
	bool meldunekBool = false;
	int meldunekInt = 0;
	int indeks = 0;
	for (std::vector<Karta>::iterator it1 = reka.begin(); it1 != reka.end(); it1++)
	{
		for (std::vector<Karta>::iterator it2 = reka.begin(); it2 != reka.end(); it2++)
		{
			if ((*it1).odczytajWartosc() == krol)
			{
				if (((*it2).odczytajWartosc() == dama) && ((*it2).odczytajKolor() == (*it1).odczytajKolor()))
				{
					if ((*it1).odczytajKolor() == kolorAtutowy)
					{
						meldunekBool = true;
						indeks = meldunekInt;
						break;
					}
					else
					{
						meldunekBool = true;
						indeks = meldunekInt;
					}
				}
			}
		}
		meldunekInt += 1;
	}
	if (meldunekBool == false)
	{
		indeks = 7;
	}
	return indeks;
}*/

