#pragma once
#include <vector>
#include "Komorka.h"
class Pole
{
	// warunki brzegowe - przeplywajace lub krancowe

	//PRYPOMINAM ZE JEST TO IV CWIARTKA UKLADU WSPOLRZEDNYCH

	//ewolucja = tura
	//

public:
	int rozmiar;
	bool czyMoorea;
	bool czyPrzeplywajace;
	std::vector<std::vector<class Komorka>> plansza; // UTILITY. to trzeba bedzie zapisac do pliku

	Pole(int rozmiar, bool czyMoorea, int iloscWartosci, bool czyPrzeplywajace);
	~Pole();

	void wykonajTure();
	void wprowadzKomorke(int x, int y, std::vector<float> wartosci);

	void wykonajTurePrzejsciePierwsze();
	void wykonajTurePrzejscieDrugie();

};

