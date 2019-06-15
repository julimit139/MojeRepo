#include "rozgrywka.h"

//Deklaracje funkcji zdefiniownych poni¿ej funkcji main
void threadTick(int* timer, bool* end)
{
	while (!(*end))
	{
		Sleep(1000);
		(*timer)++;
		std::cout << *timer << std::endl;
	}
};



int main()
{
	Rozgrywka rozgrywka;

	sf::RenderWindow window(sf::VideoMode(1200, 650), "Gra 66", sf::Style::Titlebar | sf::Style::Close);
	
	sf::RectangleShape maskaKomputera(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	sf::RectangleShape maskaCzlowieka(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	sf::RectangleShape maskaStosu(sf::Vector2f(szerokoscMaski, wysokoscMaski));
	
	bool wyjscie = false;
	int timer = 0;
	bool endTimer = false;
	std::thread Timer(threadTick, &timer, &endTimer);
	

	Talia talia;
	talia.tasujKarty();

	Kolor kolorAtutowy = talia.odczytajKolorAtutowy();

	Gracz komputer(talia);
	Gracz czlowiek(talia);

	rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	Sleep(1000);

	rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	rozgrywka.wyswietlKolorAtutowy(window, talia, wspolrzednaKoloruAtutowegoX, wspolrzednaKoloruAtutowegoY);
	window.display();
	Sleep(1500);

	rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
	rozgrywka.zakryjKolorAtutowy(window, maskaKomputera, wspolrzednaKoloruAtutowegoX, wspolrzednaKoloruAtutowegoY);
	window.display();
	Sleep(1000);


	std::string ktoWygral = "komputer";
	Karta kartaKomputera;
	Karta kartaCzlowieka;

	while (window.isOpen())
	{	
		//pierwsza czêœæ gry - ze stosem kart
		while (talia.odczytajDlugoscTalii() != 0)
		{
			rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			Sleep(1000);

			if (ktoWygral == "komputer")
			{
				rozgrywka.ruchKomputeraPierwszy1(window, komputer, czlowiek, kartaKomputera, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				rozgrywka.ruchCzlowieka1(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			}
			else if (ktoWygral == "czlowiek")
			{
				rozgrywka.ruchCzlowieka1(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				rozgrywka.ruchKomputeraDrugi1(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			}

			int punkty = rozgrywka.porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			ktoWygral = rozgrywka.powiedzKtoWygral(punkty);
			//dodajLewe(komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral);
			rozgrywka.dodajPunkty(komputer, czlowiek, punkty);

			Sleep(1000);
			rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			window.display();
			Sleep(1000);

			rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaCzlowieka);
			window.display();
			Sleep(500);

			rozgrywka.wyswietlStol1(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzednaStosuX, wspolrzednaStosuY, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			rozgrywka.wyswietlWygranaLewe(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral, wspolrzednaLewX, wspolrzedneLewY);
			window.display();
			Sleep(1500);

			rozgrywka.pobierzKarty(komputer, czlowiek, kartaKomputera, kartaCzlowieka, talia, punkty);
		}

	
		//druga czêœæ gry - bez stosu kart
		int tablicaKomputera[6] = { 1, 2, 3, 4, 5, 6 };
		int tablicaCzlowieka[6] = { 1, 2, 3, 4, 5, 6 };


		rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
		Sleep(1000);
		
		for (int i = 0; i < rozmiarReki; i++)
		{
			rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			Sleep(2000);

			if (ktoWygral == "komputer")
			{
				rozgrywka.ruchKomputeraPierwszy2(window, komputer, czlowiek, kartaKomputera, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, tablicaKomputera, tablicaCzlowieka, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				rozgrywka.ruchCzlowieka2(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, tablicaKomputera, tablicaCzlowieka, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

			}
			else if (ktoWygral == "czlowiek")
			{
				rozgrywka.ruchCzlowieka2(window, komputer, czlowiek, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[1], wspolrzednaWylozonychKartY, wysokoscKarty, szerokoscKarty, tablicaKomputera, tablicaCzlowieka, maskaCzlowieka, wyjscie, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

				rozgrywka.ruchKomputeraDrugi2(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, wspolrzedneRekiX, wspolrzedneRekiY, wspolrzedneWylozonychKartX[0], wspolrzednaWylozonychKartY, tablicaKomputera, tablicaCzlowieka, maskaKomputera, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);

			}

			int punkty = rozgrywka.porownajKarty(kartaKomputera, kartaCzlowieka, kolorAtutowy, ktoWygral);
			ktoWygral = rozgrywka.powiedzKtoWygral(punkty);
			//dodajLewe(komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral);
			rozgrywka.dodajPunkty(komputer, czlowiek, punkty);

			Sleep(1000);
			rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			window.display();
			Sleep(1000);

			rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			komputer.zakryjWyswietlonaKarteKomputera(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaKomputera);
			czlowiek.zakryjWyswietlonaKarteCzlowieka(window, wspolrzedneWylozonychKartX, wspolrzednaWylozonychKartY, maskaCzlowieka);
			window.display();
			Sleep(500);

			rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
			rozgrywka.wyswietlWygranaLewe(window, komputer, czlowiek, kartaKomputera, kartaCzlowieka, ktoWygral, wspolrzednaLewX, wspolrzedneLewY);
			window.display();
			Sleep(1500);

		}

		rozgrywka.wyswietlStol2(window, komputer, czlowiek, wspolrzedneRekiX, wspolrzedneRekiY, tablicaKomputera, tablicaCzlowieka, wspolrzednaTekstuKomputeraX, wspolrzednaTekstuKomputeraY, wspolrzednaPunktowKomputeraX, wspolrzednaPunktowKomputeraY, wspolrzednaTekstuCzlowiekaX, wspolrzednaTekstuCzlowiekaY, wspolrzednaPunktowCzlowiekaX, wspolrzednaPunktowCzlowiekaY);
		Sleep(1500);
		
		endTimer = true;
		Sleep(2000);

		//zakoñczenie gry
		rozgrywka.wyswietlInformacjeKoncowe(window, komputer, czlowiek, timer, wspolrzednaTekstuOWygranejX, wspolrzednaTekstuOWygranejY, wspolrzednaTekstuOCzasieX, wspolrzednaTekstuOCzasieY, wspolrzednaCzasuX, wspolrzednaCzasuY);
		Sleep(4000);

		endTimer = true;
		Timer.join();

		window.close();
	}

	return 0;
	getchar();
}





//Definicje funkcji zadeklarowanych powy¿ej funkcji main

