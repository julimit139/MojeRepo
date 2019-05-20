#include "talia.h"

Talia::Talia()
{
	talia.push_back(Karta(dziewiatka, pik));
	talia.push_back(Karta(walet, pik));
	talia.push_back(Karta(dama, pik));
	talia.push_back(Karta(krol, pik));
	talia.push_back(Karta(dziesiatka, pik));
	talia.push_back(Karta(as, pik));
	talia.push_back(Karta(dziewiatka, kier));
	talia.push_back(Karta(walet, kier));
	talia.push_back(Karta(dama, kier));
	talia.push_back(Karta(krol, kier));
	talia.push_back(Karta(dziesiatka, kier));
	talia.push_back(Karta(as, kier));
	talia.push_back(Karta(dziewiatka, karo));
	talia.push_back(Karta(walet, karo));
	talia.push_back(Karta(dama, karo));
	talia.push_back(Karta(krol, karo));
	talia.push_back(Karta(dziesiatka, karo));
	talia.push_back(Karta(as, karo));
	talia.push_back(Karta(dziewiatka, trefl));
	talia.push_back(Karta(walet, trefl));
	talia.push_back(Karta(dama, trefl));
	talia.push_back(Karta(krol, trefl));
	talia.push_back(Karta(dziesiatka, trefl));
	talia.push_back(Karta(as, trefl));
}

int Talia::tasujKarty()
{
	srand(time(NULL));
	std::random_shuffle(talia.begin(), talia.end());
	for (std::vector<Karta>::iterator it = talia.begin(); it != talia.end(); it++) //wypisanie potasowanej talii na ekran (roboczo)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}

/*Karta Talia::zdejmij_karte()
{
	dlugosc -= 1;
	return talia[dlugosc];
}

Kolor Talia::odczytaj_kolor_atutowy()
{
	Kolor kolor_atutowy = talia[0].odczytaj_kolor();
	switch (kolor_atutowy)
	{
	case pik:
		kolor_atutowy = pik;
		break;
	case kier:
		kolor_atutowy = kier;
		break;
	case karo:
		kolor_atutowy = karo;
		break;
	case trefl:
		kolor_atutowy = trefl;
		break;
	}
	return kolor_atutowy;
}

void Talia::wypisz_kolor_atutowy(Kolor kolor_atutowy)
{
	switch (kolor_atutowy)
	{
	case pik:
		cout << "Kolor atutowy w tej grze to pik.\n";
		break;
	case kier:
		cout << "Kolor atutowy w tej grze to kier.\n";
		break;
	case karo:
		cout << "Kolor atutowy w tej grze to karo.\n";
		break;
	case trefl:
		cout << "Kolor atutowy w tej grze to trefl.\n";
		break;
	}
}

Wartosc Talia::odczytaj_wartosc_odkrytej_karty_atutowej()
{
	return talia[0].odczytaj_wartosc();
}*/

int Talia::odczytajDlugoscTalii()
{
	return talia.size();
}

/*void Talia::podmien_karte_w_talii(Karta karta_do_podmiany)
{
	talia[0] = Karta(karta_do_podmiany.odczytaj_wartosc(), odczytaj_kolor_atutowy());
}

void Talia::wyswietl_talie()
{
	for (int i = 0; i < rozmiar_talii; i++)
	{
		cout << talia[i] << endl;
	}
}*/