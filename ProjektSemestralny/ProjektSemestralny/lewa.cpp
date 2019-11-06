#include "lewa.h"

Lewa::Lewa()
{

}

Lewa::Lewa(Karta kartaKomputera, Karta kartaCzlowieka)
{
	lewa.push_back(kartaKomputera);
	lewa.push_back(kartaCzlowieka);
}