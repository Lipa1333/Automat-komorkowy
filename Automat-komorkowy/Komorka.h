#pragma once

#include <vector>
#include "Pole.h"
#include "GUI.h"
class Komorka
{
public:

	//!variable to check kind of boundary conditions
	static bool czyPrzeplywajace;

	//!Number of values
	static int iloscWartosci;

	//!Reference pointing to cells set
	static class Pole * pole;

	//!values that cell contains
	std::vector<float> wartosci;

	//!used to perform evolution
	std::vector<float> przyszleWartosci;

	//!position of cell
	int x;

	//!position of cell
	int y;

	//!set of cell's neighbors
	std::vector<Komorka*> sasiedzi;

	//!pointer to JavaScript function to perform script (evolution action)
	static std::vector<float>(*dzialanie)(std::vector<float> v, std::vector<std::vector<float>> n,class  GUI * Window); 

	//!Main Constructor.Fills values with 0
	Komorka(int y, int x);
	
	//!Default desctructor
	~Komorka();

	//!Function to fill references to neighbors
	void ustalSasiadow();
};

