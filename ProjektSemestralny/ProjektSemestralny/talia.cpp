#include "talia.h"

Talia::Talia()
{
	talia.push_back(Karta(dziewiatka, pik,"dziewiatka_pik.jpg"));
	talia.push_back(Karta(walet, pik, "walet_pik.jpg"));
	talia.push_back(Karta(dama, pik, "dama_pik.jpg"));
	talia.push_back(Karta(krol, pik, "krol_pik.jpg"));
	talia.push_back(Karta(dziesiatka, pik, "dziesiatka_pik.jpg"));
	talia.push_back(Karta(as, pik, "as_pik.jpg"));
	talia.push_back(Karta(dziewiatka, kier, "dziewiatka_kier.jpg"));
	talia.push_back(Karta(walet, kier, "walet_kier.jpg"));
	talia.push_back(Karta(dama, kier, "dama_kier.jpg"));
	talia.push_back(Karta(krol, kier, "krol_kier.jpg"));
	talia.push_back(Karta(dziesiatka, kier, "dziesiatka_kier.jpg"));
	talia.push_back(Karta(as, kier, "as_kier.jpg"));
	talia.push_back(Karta(dziewiatka, karo, "dziewiatka_karo.jpg"));
	talia.push_back(Karta(walet, karo, "walet_karo.jpg"));
	talia.push_back(Karta(dama, karo, "dama_karo.jpg"));
	talia.push_back(Karta(krol, karo, "krol_karo.jpg"));
	talia.push_back(Karta(dziesiatka, karo, "dziesiatka_karo.jpg"));
	talia.push_back(Karta(as, karo, "as_karo.jpg"));
	talia.push_back(Karta(dziewiatka, trefl, "dziewiatka_trefl.jpg"));
	talia.push_back(Karta(walet, trefl, "walet_trefl.jpg"));
	talia.push_back(Karta(dama, trefl, "dama_trefl.jpg"));
	talia.push_back(Karta(krol, trefl, "krol_trefl.jpg"));
	talia.push_back(Karta(dziesiatka, trefl, "dziesiatka_trefl.jpg"));
	talia.push_back(Karta(as, trefl, "as_trefl.jpg"));
}

int Talia::tasujKarty()
{
	srand(time(NULL));
	std::random_shuffle(talia.begin(), talia.end());
	return 0;
}

Karta Talia::zdejmijKarte()
{
	Karta kartaRobocza(talia.rbegin()->odczytajWartosc(), talia.rbegin()->odczytajKolor(), talia.rbegin()->odczytajNazweObrazu());
	talia.pop_back();
	return kartaRobocza;
}

int Talia::odczytajDlugoscTalii()
{
	return talia.size();
}

Kolor Talia::odczytajKolorAtutowy()
{
	Kolor kolorAtutowy = talia.begin()->odczytajKolor();
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

Wartosc Talia::odczytajWartoscOdkrytejKartyAtutowej()
{
	return talia.begin()->odczytajWartosc();
}

Karta & Talia::pokazKarteAtutowa()
{
	return *(talia.begin());
}