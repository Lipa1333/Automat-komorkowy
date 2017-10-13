#pragma once

#include <vector>

class Komorka
{
public:
	//dane wejsciowe ze skryptu :
	// dla kazdej z komorek:
	// ilosc wartosci i same wartosci
	// zdefiniowane stany i ich warunki
	// zdefiniowane dzialanie

	bool czyAgent;
	int iloscWartosci;

	std::vector<float> wartosci;   // wartosci o ktorych byla mowa
	
	short przyszlyStan;
	//talica stanow - dostarczana ze skryptem lub predefiniowana


	void(*dzialanie)(); // tymczasowe, wskaznik na funkcje ktora bedzie zapisana w skrypcie

	Komorka();
	~Komorka();
};

