#pragma once

const int rozmiarTalii = 24;												//sta�a przechowuj�ca rozmiar talii
const int rozmiarReki = 6;													//sta�a przechowuj�ca rozmiar r�ki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as };	//typ wyliczeniowy zawieraj�cy warto�ci kart
enum Kolor { pik, kier, karo, trefl };										//typ wyliczeniowy zawieraj�cy kolory kart

const int szerokoscKarty = 123;												//sta�a przechowuj�ca szeroko�� karty	
const int wysokoscKarty = 170;												//sta�a przechowuj�ca wysoko�� karty
const float szerokoscMaski = 130;											//sta�a przechowuj�ca szeroko�� maski	
const float wysokoscMaski = 177;											//sta�a przechowuj�ca wysoko�� maski			
const float wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };			//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart w r�kach graczy
const float wspolrzedneRekiY[2] = { 20, 470 };								//tablica przechowuj�ca wsp�rz�dne y lewych g�rnych rog�w kart w r�kach graczy
const float wspolrzednaStosuX = 79;											//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu stosu
const float wspolrzednaStosuY = 245;										//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu stosu
const float wspolrzednaKoloruAtutowegoX = 519;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy
const float wspolrzednaKoloruAtutowegoY = 245;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu karty wyznaczaj�cej kolor atutowy			
const float wspolrzednaLewX = 1044;											//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu kart wygrywaj�cych w lewach
const float wspolrzedneLewY[2] = { 20, 470 };								//tablica przechowuj�ca wsp�rz�dne y lewych g�rnych rog�w kart wygrywaj�cych w lewach
const float wspolrzedneWylozonychKartX[2] = {444, 594};						//tablica przechowuj�ca wsp�rz�dne x lewych g�rnych rog�w kart wy�o�onych przez graczy
const float wspolrzednaWylozonychKartY = 245;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu kart wy�o�onych przez graczy
const float wspolrzednaTekstuPowitalnegoX = 400;							//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu tekstu powitalnego 
const float wspolrzednaTekstuPowitalnegoY = 300;							//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu tekstu powitalnego
const float wspolrzednaTekstuOWygranejX = 200;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu tekstu informuj�cego o zwyci�zcy rozgrywki 
const float wspolrzednaTekstuOWygranejY = 300;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu tekstu informuj�cego o zwyci�zcy rozgrywki
const float wspolrzednaTekstuOCzasieX = 100;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu tekstu informuj�cego o czasie trwania rozgrywki
const float wspolrzednaTekstuOCzasieY = 400;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu tekstu informuj�cego o czasie trwania rozgrywki 
const float wspolrzednaCzasuX = 1100;										//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu liczby sekund trwania rozgryki
const float wspolrzednaCzasuY = 400;										//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu liczby sekund trwania rozgryki
const float wspolrzednaTekstuKomputeraX = 1050;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu napisu "KOMPUTER"
const float wspolrzednaTekstuKomputeraY = 245;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu napisy "KOMPUTER"
const float wspolrzednaPunktowKomputeraX = 1098;							//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu liczby punkt�w komputera
const float wspolrzednaPunktowKomputeraY = 280;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu liczby punkt�w komputera
const float wspolrzednaTekstuCzlowiekaX = 1093;								//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu napisu "CZLOWIEK"
const float wspolrzednaTekstuCzlowiekaY = 350;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu napisu "CZLOWIEK"
const float wspolrzednaPunktowCzlowiekaX = 1098;							//sta�a przechowuj�ca wsp�rz�dn� x lewego g�rnego rogu liczby punkt�w cz�owieka
const float wspolrzednaPunktowCzlowiekaY = 385;								//sta�a przechowuj�ca wsp�rz�dn� y lewego g�rnego rogu liczby punkt�w cz�owieka