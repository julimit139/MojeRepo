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
	return 0;
}

Karta Talia::zdejmijKarte()
{
	Karta kartaRobocza(talia.rbegin()->odczytaj_wartosc(), talia.rbegin()->odczytaj_kolor());
	talia.pop_back();
	return kartaRobocza;
}

Kolor Talia::odczytajKolorAtutowy()
{
	Kolor kolorAtutowy = talia.begin()->odczytaj_kolor();
	switch (kolorAtutowy)
	{
	case pik:
		kolorAtutowy = pik;
		break;
	case kier:
		kolorAtutowy = kier;
		break;
	case karo:
		kolorAtutowy = karo;
		break;
	case trefl:
		kolorAtutowy = trefl;
		break;
	}
	return kolorAtutowy;
}

/*void Talia::wypisz_kolor_atutowy(Kolor kolor_atutowy)
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
}*/

void Talia::wyswietlTalie()
{
	for (std::vector<Karta>::iterator it = talia.begin(); it != talia.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}