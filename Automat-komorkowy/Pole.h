#pragma once
#include <vector>
#include "Komorka.h"
class Pole
{
	
public:

	//!Variable to contain information about size of set
	int rozmiar;

	//!Contains information about neighbourhood
	bool czyMoorea;

	//!Real set of Cells
	std::vector<std::vector<class Komorka>> plansza;

	//!Main Constructor
	Pole(int rozmiar, bool czyMoorea, int iloscWartosci, bool czyPrzeplywajace);

	//!Default desctructor
	~Pole();

	//!Method to execute evolution
	void wykonajTure(class GUI * Window);

	//!Method to edit Cell
	void wprowadzKomorke(int x, int y, std::vector<float> wartosci);

	//!First part of the evolution
	void wykonajTurePrzejsciePierwsze(class GUI * Window);

	//!Second part of the evolution
	void wykonajTurePrzejscieDrugie();

};

