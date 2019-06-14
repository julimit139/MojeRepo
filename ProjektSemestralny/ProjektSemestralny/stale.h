#pragma once

const int rozmiar_talii = 24;												//sta³a przechowuj¹ca rozmiar talii
const int rozmiar_reki = 6;													//sta³a przechowuj¹ca rozmiar rêki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as };	//typ wyliczeniowy zawieraj¹cy wartoœci kart
enum Kolor { pik, kier, karo, trefl };										//typ wyliczeniowy zawieraj¹cy kolory kart

const int wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };			//tablica przechowuj¹ca wspó³rzêdne x lewych górnych rogów kart w rêkach graczy
const int wspolrzedneRekiY[2] = { 20, 470 };								//tablica przechowuj¹ca wspó³rzêdne y lewych górnych rogów kart w rêkach graczy
const int wspolrzednaStosuX = 79;											//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu stosu
const int wspolrzednaStosuY = 245;											//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu stosu
const int wspolrzednaKoloruAtutowegoX = 519;								//sta³a przechowuj¹ca wspó³rzêdn¹ x lewego górnego rogu karty wyznaczaj¹cej kolor atutowy
const int wspolrzednaKoloruAtutowegoY = 245;								//sta³a przechowuj¹ca wspó³rzêdn¹ y lewego górnego rogu karty wyznaczaj¹cej kolor atutowy			
const int wspolrzedneXWylozonychKart[2] = {444, 594};						//tablica przechowuj¹ca wspó³rzêdne x lewych górnych rogów kart wy³o¿onych przez graczy
const int szerokoscKarty = 123;												//sta³a przechowuj¹ca szerokoœæ karty	
const int wysokoscKarty = 170;												//sta³a przechowuj¹ca wysokoœæ karty