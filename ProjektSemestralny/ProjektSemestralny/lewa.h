#pragma once
#include "karta.h"
#include <vector>

class Lewa
{
	std::vector<Karta> lewa;			//wektor kart - lewa
public:
	Lewa();				//konstruktor domy�lny obiektu klasy Lewa
	Lewa(Karta pierwsza, Karta druga);			//konstruktor obiektu klasy Lewa
	//Karta & operator[](int indeks);				//prze�adowany operator indeksowania, umo�liwia dostanie si� do konkretnego elementu tablicy
	//friend std::ostream & operator << (std::ostream & wypisz, Lewa lewa);				//zaprzyja�niona funkcja wypisuj�ca lew� na ekran
};

//std::ostream & operator << (std::ostream & wypisz, Lewa lewa); //funkcja wypisuj�ca lew� na ekran
