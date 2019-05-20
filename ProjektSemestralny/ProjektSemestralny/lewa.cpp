#include "lewa.h"

Lewa::Lewa()
{

}

Lewa::Lewa(Karta pierwsza, Karta druga)
{
	lewa.push_back(pierwsza);
	lewa.push_back(druga);
}

/*Karta & Lewa::operator[](int indeks)
{
	return this->lewa[indeks];
}

std::ostream & operator << (std::ostream & wypisz, Lewa lewa)
{
	
	return wypisz;
}*/