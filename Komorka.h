#pragma once

#include <vector>
#include "Pole.h"
#include "GUI.h"
class Komorka
{
public:
	//dane wejsciowe ze skryptu :
	// dla kazdej z komorek:
	// ilosc wartosci i same wartosci
	// zdefiniowane stany i ich warunki
	// zdefiniowane dzialanie

	bool czyAgent;

	static bool czyPrzeplywajace;

	static int iloscWartosci;

	static class Pole * pole;

	std::vector<float> wartosci;// wartosci o ktorych byla mowa

	std::vector<float> przyszleWartosci;// wartosci o ktorych byla mowa

	int x;
	int y;


	std::vector<Komorka*> sasiedzi;

	//brak interpretacji stanow- kazda komorka caly czas zyje

	static std::vector<float>(*dzialanie)(std::vector<float> v, std::vector<std::vector<float>> n,class  GUI * Window); // tymczasowe, wskaznik na funkcje ktora bedzie zapisana w skrypci



	Komorka();
	Komorka(int y, int x);
	~Komorka();
	void ustalSasiadow();
	Komorka operator=(const Komorka & v); //deprecated
};

