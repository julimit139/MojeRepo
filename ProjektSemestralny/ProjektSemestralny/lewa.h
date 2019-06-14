#pragma once
#include "karta.h"
#include <vector>

class Lewa
{
	std::vector<Karta> lewa;			//wektor kart - lewa
public:
	Lewa();				//konstruktor domyœlny obiektu klasy Lewa
	Lewa(Karta pierwsza, Karta druga);			//konstruktor obiektu klasy Lewa
	//Karta & operator[](int indeks);				//prze³adowany operator indeksowania, umo¿liwia dostanie siê do konkretnego elementu tablicy
	//friend std::ostream & operator << (std::ostream & wypisz, Lewa lewa);				//zaprzyjaŸniona funkcja wypisuj¹ca lewê na ekran
};

//std::ostream & operator << (std::ostream & wypisz, Lewa lewa); //funkcja wypisuj¹ca lewê na ekran
