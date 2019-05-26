#include "reka.h"

Reka::Reka(Talia & talia)
{
	for (int i = 0; i < rozmiar_reki; i++)
	{
		reka.push_back(talia.zdejmijKarte());
	}
	kolorAtutowy = talia.odczytajKolorAtutowy();
}

/*Karta & Reka::operator[](int indeks)
{
	return this->reka[indeks];
}*/

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

/*Karta Reka::dobierz_karte_1(Karta karta_wylozona)
{
	Karta * karta_dobrana = NULL;
	if (karta_wylozona.odczytaj_kolor() == kolor_atutowy)
	{
		for (int i = 0; i < rozmiar_reki; i++)
		{
			if (reka[i].odczytaj_kolor() == kolor_atutowy)
			{
				if (reka[i].odczytaj_wartosc() > karta_wylozona.odczytaj_wartosc())
				{
					if (karta_dobrana == NULL)
					{
						karta_dobrana = &reka[i];
					}
					if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
					{
						karta_dobrana = &reka[i];
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (reka[i].odczytaj_kolor() != kolor_atutowy)
				{
					if (karta_dobrana == NULL)
					{
						karta_dobrana = &reka[i];
					}
					if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
					{
						karta_dobrana = &reka[i];
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < rozmiar_reki; i++)
		{
			if (reka[i].odczytaj_kolor() == karta_wylozona.odczytaj_kolor())
			{
				if (reka[i].odczytaj_wartosc() > karta_wylozona.odczytaj_wartosc())
				{
					if (karta_dobrana == NULL)
					{
						karta_dobrana = &reka[i];
					}
					if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
					{
						karta_dobrana = &reka[i];
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (reka[i].odczytaj_kolor() == kolor_atutowy)
				{
					if (karta_dobrana == NULL)
					{
						karta_dobrana = &reka[i];
					}
					if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
					{
						karta_dobrana = &reka[i];
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if ((reka[i].odczytaj_kolor() != karta_wylozona.odczytaj_kolor()) && (reka[i].odczytaj_kolor() != kolor_atutowy))
				{
					if (karta_dobrana == NULL)
					{
						karta_dobrana = &reka[i];
					}
					if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
					{
						karta_dobrana = &reka[i];
					}
				}
			}
		}
	}
	return *karta_dobrana;
}

Karta Reka::dobierz_karte_2(Karta karta_wylozona, int * tab)
{
	Karta * karta_dobrana = NULL;
	if (karta_wylozona.odczytaj_kolor() == kolor_atutowy)
	{
		for (int i = 0; i < rozmiar_reki; i++)
		{
			if (tab[i] != 0)
			{
				if (reka[i].odczytaj_kolor() == kolor_atutowy)
				{
					if (reka[i].odczytaj_wartosc() > karta_wylozona.odczytaj_wartosc())
					{
						if (karta_dobrana == NULL)
						{
							karta_dobrana = &reka[i];
						}
						if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
						{
							karta_dobrana = &reka[i];
						}
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (tab[i] != 0)
				{
					if (reka[i].odczytaj_kolor() == kolor_atutowy)
					{
						if (reka[i].odczytaj_wartosc() < karta_wylozona.odczytaj_wartosc())
						{
							if (karta_dobrana == NULL)
							{
								karta_dobrana = &reka[i];
							}
							if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
							{
								karta_dobrana = &reka[i];
							}
						}
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (tab[i] != 0)
				{
					if (reka[i].odczytaj_kolor() != kolor_atutowy)
					{
						if (karta_dobrana == NULL)
						{
							karta_dobrana = &reka[i];
						}
						if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
						{
							karta_dobrana = &reka[i];
						}
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < rozmiar_reki; i++)
		{
			if (tab[i] != 0)
			{
				if (reka[i].odczytaj_kolor() == karta_wylozona.odczytaj_kolor())
				{
					if (reka[i].odczytaj_wartosc() > karta_wylozona.odczytaj_wartosc())
					{
						if (karta_dobrana == NULL)
						{
							karta_dobrana = &reka[i];
						}
						if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
						{
							karta_dobrana = &reka[i];
						}
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (tab[i] != 0)
				{
					if (reka[i].odczytaj_kolor() == karta_wylozona.odczytaj_kolor())
					{
						if (reka[i].odczytaj_wartosc() < karta_wylozona.odczytaj_wartosc())
						{
							if (karta_dobrana == NULL)
							{
								karta_dobrana = &reka[i];
							}
							if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
							{
								karta_dobrana = &reka[i];
							}
						}
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (tab[i] != 0)
				{
					if (reka[i].odczytaj_kolor() == kolor_atutowy)
					{
						if (karta_dobrana == NULL)
						{
							karta_dobrana = &reka[i];
						}
						if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
						{
							karta_dobrana = &reka[i];
						}
					}
				}
			}
		}
		if (karta_dobrana == NULL)
		{
			for (int i = 0; i < rozmiar_reki; i++)
			{
				if (tab[i] != 0)
				{
					if ((reka[i].odczytaj_kolor() != karta_wylozona.odczytaj_kolor()) && (reka[i].odczytaj_kolor() != kolor_atutowy))
					{
						if (karta_dobrana == NULL)
						{
							karta_dobrana = &reka[i];
						}
						if ((karta_dobrana != NULL) && (reka[i].odczytaj_wartosc() < karta_dobrana->odczytaj_wartosc()))
						{
							karta_dobrana = &reka[i];
						}
					}
				}
			}
		}
	}
	return *karta_dobrana;
}*/

void Reka::wyswietlAktualnaReke()
{
	int indeks = 0;
	std::cout << "Twoja aktualna reka to:\n\n";
	for (std::vector<Karta>::iterator it = reka.begin(); it != reka.end(); it++)
	{
		std::cout << (indeks + 1) << ". " << (*it) << std::endl;
		indeks += 1;
	}
}

/*void Reka::wyswietl_aktualna_reke_pomniejszona(int * tab)
{
	cout << "Twoja aktualna reka to:\n\n";
	for (int i = 0; i < rozmiar_reki; i++)
	{
		if (tab[i] == 0)
		{
			cout << i + 1 << ". ---\n";
		}
		else
		{
			cout << i + 1 << ". " << reka[i] << endl;
		}
	}
}*/

int Reka::sprawdzWarunekPodmiany()
{
	int podmianaBool = false;
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
	reka[indeks] = Karta(w, kolorAtutowy);
	talia.podmienKarteWTalii(tmp);
}

/*int Reka::sprawdzMeldunek()
{
	int indeks = 7;
	for (int i = 0; i < rozmiar_reki; i++)
	{
		for (int j = 0; j < rozmiar_reki; j++)
		{
			if (reka[i].odczytaj_wartosc() == krol)
			{
				if ((reka[j].odczytaj_wartosc() == dama) && (reka[j].odczytaj_kolor() == reka[i].odczytaj_kolor()))
				{
					if (reka[i].odczytaj_kolor() == kolorAtutowy)
					{
						indeks = i;
						return indeks;
					}
					else
					{
						indeks = i;
					}
				}
			}
		}
	}
	return indeks;
}*/