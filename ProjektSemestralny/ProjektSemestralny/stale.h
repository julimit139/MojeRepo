#pragma once

const int rozmiar_talii = 24; //sta³a przechowuj¹ca rozmiar talii
const int rozmiar_reki = 6; //sta³a przechowuj¹ca rozmiar rêki

enum Wartosc { dziewiatka, walet = 2, dama, krol, dziesiatka = 10, as }; //typ wyliczeniowy zawieraj¹cy wartoœci kart
enum Kolor { pik, kier, karo, trefl }; //typ wyliczeniowy zawieraj¹cy kolory kart

const int wspolrzedneRekiX[6] = { 144, 294, 444, 594, 744, 894 };
const int wspolrzedneRekiY[2] = { 20, 470 };
const int wspolrzednaStosuX = 79;
const int wspolerzednaStosuY = 245;
const int wspolrzedneXWylozonychKart[2] = {444, 594};
const int szerokoscKarty = 123;
const int wysokoscKarty = 170;