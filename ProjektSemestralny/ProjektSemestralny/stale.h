#pragma once

const int rozmiar_talii = 24;												//sta�a przechowuj�ca rozmiar talii
const int rozmiar_reki = 6;													//sta�a przechowuj�ca rozmiar r�ki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as };	//typ wyliczeniowy zawieraj�cy warto�ci kart
enum Kolor { pik, kier, karo, trefl };										//typ wyliczeniowy zawieraj�cy kolory kart

const int wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };			//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart w r�kach graczy
const int wspolrzedneRekiY[2] = { 20, 470 };								//tablica przechowuj�ca wsp�rz�dne y lewych g�rnych rog�w kart w r�kach graczy
const int wspolrzednaStosuX = 79;											//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu stosu
const int wspolrzednaStosuY = 245;											//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu stosu
const int wspolrzednaKoloruAtutowegoX = 519;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy
const int wspolrzednaKoloruAtutowegoY = 245;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy			
const int wspolrzedneXWylozonychKart[2] = {444, 594};						//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart wy�o�onych przez graczy
const int szerokoscKarty = 123;												//sta�a przechowuj�ca szeroko�� karty	
const int wysokoscKarty = 170;												//sta�a przechowuj�ca wysoko�� karty