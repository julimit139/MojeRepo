#pragma once

const int rozmiarTalii = 24;												//sta�a przechowuj�ca rozmiar talii
const int rozmiarReki = 6;													//sta�a przechowuj�ca rozmiar r�ki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as };	//typ wyliczeniowy zawieraj�cy warto�ci kart
enum Kolor { pik, kier, karo, trefl };										//typ wyliczeniowy zawieraj�cy kolory kart

const int szerokoscKarty = 123;												//sta�a przechowuj�ca szeroko�� karty	
const int wysokoscKarty = 170;												//sta�a przechowuj�ca wysoko�� karty
const float szerokoscMaski = 130;
const float wysokoscMaski = 177;
const float wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };			//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart w r�kach graczy
const float wspolrzedneRekiY[2] = { 20, 470 };								//tablica przechowuj�ca wsp�rz�dne y lewych g�rnych rog�w kart w r�kach graczy
const float wspolrzednaStosuX = 79;											//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu stosu
const float wspolrzednaStosuY = 245;											//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu stosu
const float wspolrzednaKoloruAtutowegoX = 519;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy
const float wspolrzednaKoloruAtutowegoY = 245;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy			
const float wspolrzednaLewX = 1044;											//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu lew
const float wspolrzedneLewY[2] = { 20, 470 };									//tablica przechowuj�ca wsp�rz�dne y lewych g�rnych rog�w lew
const float wspolrzedneWylozonychKartX[2] = {444, 594};						//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart wy�o�onych przez graczy
const float wspolrzednaWylozonychKartY = 245;									//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu kart wy�o�onych przez graczy
const float wspolrzednaTekstuOWygranejX = 200;
const float wspolrzednaTekstuOWygranejY = 300;
const float wspolrzednaTekstuOCzasieX = 100;
const float wspolrzednaTekstuOCzasieY = 400;
const float wspolrzednaCzasuX = 1100;
const float wspolrzednaCzasuY = 400;
const float wspolrzednaTekstuKomputeraX = 1050;
const float wspolrzednaTekstuKomputeraY = 245;
const float wspolrzednaPunktowKomputeraX = 1098;
const float wspolrzednaPunktowKomputeraY = 280;
const float wspolrzednaTekstuCzlowiekaX = 1093;
const float wspolrzednaTekstuCzlowiekaY = 350;
const float wspolrzednaPunktowCzlowiekaX = 1098;
const float wspolrzednaPunktowCzlowiekaY = 385;