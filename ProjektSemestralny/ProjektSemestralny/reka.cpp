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
}

void Reka::pobierz_karte(Talia & talia, int indeks)
{
	reka[indeks] = talia.zdejmij_karte();
}

Karta & Reka::wez_karte_spod_indeksu_1(int indeks)
{
	return reka[indeks];
}

Karta & Reka::wez_karte_spod_indeksu_2(int indeks, int * tab)
{
	tab[indeks] = 0;
	return reka[indeks];
}

int Reka::znajdz_indeks(Karta karta)
{
	int indeks = 0;
	for (int i = 0; i < rozmiar_reki; i++)
	{
		if ((reka[i].odczytaj_wartosc() == karta.odczytaj_wartosc()) && (reka[i].odczytaj_kolor() == karta.odczytaj_kolor()))
		{
			indeks = i;
			break;
		}
	}
	return indeks;
}

Karta Reka::dobierz_karte_1(Karta karta_wylozona)
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
}

void Reka::wyswietl_aktualna_reke()
{
	cout << "Twoja aktualna reka to:\n\n";
	for (int i = 0; i < rozmiar_reki; i++)
	{
		cout << i + 1 << ". " << reka[i] << endl;
	}
}

void Reka::wyswietl_aktualna_reke_pomniejszona(int * tab)
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
}

int Reka::sprawdz_warunek_podmiany()
{
	int podmiana = 7;
	for (int i = 0; i < rozmiar_reki; i++)
	{
		if ((reka[i].odczytaj_wartosc() == dziewiatka) && (reka[i].odczytaj_kolor() == kolor_atutowy))
		{
			podmiana = i;
		}
	}
	return podmiana;
}

void Reka::podmien(Talia & talia, int indeks)
{
	Karta tmp = reka[indeks];
	Wartosc w = talia.odczytaj_wartosc_odkrytej_karty_atutowej();
	reka[indeks] = Karta(w, kolor_atutowy);
	talia.podmien_karte_w_talii(tmp);
}

int Reka::sprawdz_meldunek()
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
					if (reka[i].odczytaj_kolor() == kolor_atutowy)
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