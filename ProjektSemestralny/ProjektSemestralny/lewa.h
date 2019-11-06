#pragma once
#include "karta.h"
#include <vector>

class Lewa
{
	std::vector<Karta> lewa;				//wektor kart tworz�cy lew�
public:
	Lewa();													//konstruktor domy�lny obiektu klasy Lewa
	Lewa(Karta kartaKomputera, Karta kartaCzlowieka);		//konstruktor obiektu klasy Lewa
};