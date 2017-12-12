#pragma once
#include "Komorka.h"
#include "Pole.h"
#define DOMYSLNA_WARTOSC 0

Komorka::Komorka(int y, int x)
{
	this->x = x;
	this->y = y;
	this->iloscWartosci = iloscWartosci;
	for (int i = 0; i < iloscWartosci; i++)
	{
		wartosci.push_back(DOMYSLNA_WARTOSC);
	}

	przyszleWartosci = wartosci;


}

void Komorka::ustalSasiadow()
{
	int ostatni = pole->rozmiar - 1;
	if (y - 1 >= 0)
	{
		sasiedzi.push_back(&pole->plansza[y - 1][x]);
	}
	else
	{
		if (czyPrzeplywajace)
		{
			sasiedzi.push_back(&pole->plansza[ostatni][x]);
		}
	}
	//2
	if (y + 1 <= ostatni)
	{
		sasiedzi.push_back(&pole->plansza[y + 1][x]);
	}
	else
	{
		if (czyPrzeplywajace)
		{
			sasiedzi.push_back(&pole->plansza[0][x]);
		}
	}
	//4
	if (x - 1 >= 0)
	{
		sasiedzi.push_back(&pole->plansza[y][x - 1]);
	}
	else
	{
		if (czyPrzeplywajace)
		{
			sasiedzi.push_back(&pole->plansza[y][ostatni]);
		}
	}
	//6
	if (x + 1 <= ostatni)
	{
		sasiedzi.push_back(&pole->plansza[y][x + 1]);
	}
	else
	{
		if (czyPrzeplywajace)
		{
			sasiedzi.push_back(&pole->plansza[y][0]);
		}
	}
	//dodatkowe
	if (pole->czyMoorea)
	{
		//7
		if (x - 1 >= 0 && y - 1 >= 0)
		{
			sasiedzi.push_back(&pole->plansza[y - 1][x - 1]);

		}
		else
		{
			if (x - 1 < 0)
			{
				if (y - 1 < 0)
				{
					sasiedzi.push_back(&pole->plansza[ostatni][ostatni]);
				}
				else
				{
					sasiedzi.push_back(&pole->plansza[y - 1][ostatni]);
				}
			}
			else
			{
				if (y - 1 < 0)
				{
					sasiedzi.push_back(&pole->plansza[ostatni][x - 1]);
				}
			}
		}
		//9
		if (x + 1 <= ostatni && y - 1 >= 0)
		{
			sasiedzi.push_back(&pole->plansza[y - 1][x + 1]);

		}
		else
		{
			if (x + 1 > ostatni)
			{
				if (y - 1 < 0)
				{
					sasiedzi.push_back(&pole->plansza[ostatni][0]);
				}
				else
				{
					sasiedzi.push_back(&pole->plansza[y - 1][0]);
				}
			}
			else
			{
				if (y - 1 < 0)
				{
					sasiedzi.push_back(&pole->plansza[ostatni][ostatni]);
				}
			}
		}
		//1
		if (x - 1 >= 0 && y + 1 <= ostatni)
		{
			sasiedzi.push_back(&pole->plansza[y + 1][x - 1]);

		}
		else
		{
			if (x - 1 < 0)
			{
				if (y + 1 > ostatni)
				{
					sasiedzi.push_back(&pole->plansza[0][ostatni]);
				}
				else
				{
					sasiedzi.push_back(&pole->plansza[y + 1][ostatni]);
				}
			}
			else
			{
				if (y + 1 > ostatni)
				{
					sasiedzi.push_back(&pole->plansza[0][x - 1]);
				}
			}
		}
		//3
		if (x + 1 <= ostatni && y + 1 <= ostatni)
		{
			sasiedzi.push_back(&pole->plansza[y + 1][x + 1]);

		}
		else
		{
			if (x + 1 > ostatni)
			{
				if (y + 1 > ostatni)
				{
					sasiedzi.push_back(&pole->plansza[0][0]);
				}
				else
				{
					sasiedzi.push_back(&pole->plansza[y + 1][0]);
				}
			}
			else
			{
				if (y + 1 > ostatni)
				{
					sasiedzi.push_back(&pole->plansza[0][x + 1]);
				}
			}
		}
	}
}

Komorka::~Komorka()
{

}

/*
Komorka Komorka::operator=(const Komorka & v)
{
	for (int i = 0; i < iloscWartosci; i++)
	{
		this->wartosci[i] = v.wartosci[i];
	}



	return *this;
}
*/