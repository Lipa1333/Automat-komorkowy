#include "Pole.h"

#include <vector>
#include "Komorka.h"
Pole::Pole(int rozmiar = 10, bool czyMorea = true)
{
	for (int i = 0; i < rozmiar; i++)
	{
		plansza.push_back(std::vector<Komorka>(rozmiar));
		
	}
	

}