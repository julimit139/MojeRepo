#include "karta.h"

Karta::Karta()
{
	this->wartosc = dziewiatka;
	this->kolor = pik;
}

Karta::Karta(Wartosc w, Kolor k)
{
	this->wartosc = w;
	this->kolor = k;
}

Wartosc & Karta::odczytajWartosc()
{
	return this->wartosc;
}

Kolor & Karta::odczytajKolor()
{
	return this->kolor;
}

std::ostream & operator << (std::ostream & wypisz, Karta karta)
{
	switch (karta.odczytajWartosc())
	{
	case dziewiatka:
		wypisz << "9 ";
		break;
	case walet:
		wypisz << "W ";
		break;
	case dama:
		wypisz << "D ";
		break;
	case krol:
		wypisz << "K ";
		break;
	case dziesiatka:
		wypisz << "10 ";
		break;
	case as:
		wypisz << "A ";
		break;
	}
	switch (karta.odczytajKolor())
	{
	case pik:
		wypisz << "pik\n";
		break;
	case kier:
		wypisz << "kier\n";
		break;
	case karo:
		wypisz << "karo\n";
		break;
	case trefl:
		wypisz << "trefl\n";
		break;
	}
	return wypisz;
}