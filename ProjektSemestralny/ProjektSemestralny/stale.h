#pragma once

const int rozmiarTalii = 24;												//sta³a przechowuj¹ca rozmiar talii
const int rozmiarReki = 6;													//sta³a przechowuj¹ca rozmiar rêki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as };	//typ wyliczeniowy zawieraj¹cy wartoœci kart
enum Kolor { pik, kier, karo, trefl };										//typ wyliczeniowy zawieraj¹cy kolory kart

const int szerokoscKarty = 123;												//sta³a przechowuj¹ca szerokoœæ karty	
const int wysokoscKarty = 170;												//sta³a przechowuj¹ca wysokoœæ karty
const float szerokoscMaski = 130;											//sta³a przechowuj¹ca szerokoœæ maski	
const float wysokoscMaski = 177;											//sta³a przechowuj¹ca wysokoœæ maski			
const float wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };			//tablica przechowuj¹ca wspó³rzêdne x lewych górnych rogów kart w rêkach graczy
const float wspolrzedneRekiY[2] = { 20, 470 };								//tablica przechowuj¹ca wspó³rzêdne y lewych górnych rogów kart w rêkach graczy
const float wspolrzednaStosuX = 79;											//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu stosu
const float wspolrzednaStosuY = 245;										//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu stosu
const float wspolrzednaKoloruAtutowegoX = 519;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu karty wyznaczaj¹cej kolor atutowy
const float wspolrzednaKoloruAtutowegoY = 245;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu karty wyznaczaj¹cej kolor atutowy			
const float wspolrzednaLewX = 1044;											//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu kart wygrywaj¹cych w lewach
const float wspolrzedneLewY[2] = { 20, 470 };								//tablica przechowuj¹ca wspó³rzêdne y lewych górnych rogów kart wygrywaj¹cych w lewach
const float wspolrzedneWylozonychKartX[2] = {444, 594};						//tablica przechowuj¹ca wspó³rzêdne x lewych górnych rogów kart wy³o¿onych przez graczy
const float wspolrzednaWylozonychKartY = 245;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu kart wy³o¿onych przez graczy
const float wspolrzednaTekstuPowitalnegoX = 400;							//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu tekstu powitalnego 
const float wspolrzednaTekstuPowitalnegoY = 300;							//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu tekstu powitalnego
const float wspolrzednaTekstuOWygranejX = 200;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu tekstu informuj¹cego o zwyciêzcy rozgrywki 
const float wspolrzednaTekstuOWygranejY = 300;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu tekstu informuj¹cego o zwyciêzcy rozgrywki
const float wspolrzednaTekstuOCzasieX = 100;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu tekstu informuj¹cego o czasie trwania rozgrywki
const float wspolrzednaTekstuOCzasieY = 400;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu tekstu informuj¹cego o czasie trwania rozgrywki 
const float wspolrzednaCzasuX = 1100;										//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu liczby sekund trwania rozgryki
const float wspolrzednaCzasuY = 400;										//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu liczby sekund trwania rozgryki
const float wspolrzednaTekstuKomputeraX = 1050;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu napisu "KOMPUTER"
const float wspolrzednaTekstuKomputeraY = 245;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu napisy "KOMPUTER"
const float wspolrzednaPunktowKomputeraX = 1098;							//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu liczby punktów komputera
const float wspolrzednaPunktowKomputeraY = 280;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu liczby punktów komputera
const float wspolrzednaTekstuCzlowiekaX = 1093;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu napisu "CZLOWIEK"
const float wspolrzednaTekstuCzlowiekaY = 350;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu napisu "CZLOWIEK"
const float wspolrzednaPunktowCzlowiekaX = 1098;							//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu liczby punktów cz³owieka
const float wspolrzednaPunktowCzlowiekaY = 385;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu liczby punktów cz³owieka