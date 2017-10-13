#pragma once
#include <vector>
#include "Komorka.h"
class Pole
{

	
	
	//s¹siedzctwo do wyboru
	// rozszerzalna
	// warunki brzegowe - przeplywajace lub krancowe
	
	//PRYPOMINAM ZE JEST TO IV CWIARTKA UKLADU WSPOLRZEDNYCH

	//ewolucja = tura
	//

public:
	int rozmiar;
	bool czyMoorea;
	std::vector<std::vector<Komorka>> plansza; // UTILITY. to trzeba bedzie zapisac do pliku
	std::vector<Komorka *> listaAktywnychKomorek; // to rowniez
	Pole(int rozmiar,bool czyMoorea);
	~Pole();

	void SprawdzBrzegi();
	void WykonajTure();


};

