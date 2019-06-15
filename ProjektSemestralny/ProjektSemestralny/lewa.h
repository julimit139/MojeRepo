#pragma once
#include "karta.h"
#include <vector>

class Lewa
{
	std::vector<Karta> lewa;				//wektor kart tworz¹cy lewê
public:
	Lewa();													//konstruktor domyœlny obiektu klasy Lewa
	Lewa(Karta kartaKomputera, Karta kartaCzlowieka);		//konstruktor obiektu klasy Lewa
};