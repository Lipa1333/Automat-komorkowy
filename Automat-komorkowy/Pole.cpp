#pragma once
#include "Pole.h"

#include <vector>
#include "Komorka.h"
class Pole* Komorka::pole = NULL;
Pole::Pole(int rozmiar = 10, bool czyMoorea = true, int iloscWartosci = 1, bool czyPrzeplywajace = false)
{
	Komorka::iloscWartosci = iloscWartosci;
	Komorka::pole = this;
	Komorka::czyPrzeplywajace = czyPrzeplywajace;
	this->czyMoorea = czyMoorea;
	this->rozmiar = rozmiar;

	for (int i = 0; i < rozmiar; i++)
	{
		std::vector<Komorka> tmp;

		for (int j = 0; j < rozmiar; j++)
		{
			tmp.push_back(Komorka(i, j));
		}
		plansza.push_back(tmp);
	}

	for (int y = 0; y < rozmiar; y++)
	{
		for (int x = 0; x < rozmiar; x++)
		{
			plansza[y][x].ustalSasiadow();

		}
	}

}


Pole::~Pole()
{

}


void Pole::wprowadzKomorke(int x, int y, std::vector<float> wartosci)
{
	for (int i = 0; i < Komorka::iloscWartosci; i++)
	{
		plansza[y][x].wartosci[i] = wartosci[i];
	}
	plansza[y][x].przyszleWartosci = wartosci;
}

void Pole::wykonajTurePrzejsciePierwsze(GUI * Window)
{

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			std::vector<std::vector<float>> tmp;
			for (int k = 0; k < plansza[i][j].sasiedzi.size(); k++)
			{
				tmp.push_back(plansza[i][j].sasiedzi[k]->wartosci);
			}
				plansza[i][j].przyszleWartosci = Komorka::dzialanie(plansza[i][j].wartosci, tmp, Window);
		}
	}
}

void Pole::wykonajTurePrzejscieDrugie()
{
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			plansza[i][j].wartosci = plansza[i][j].przyszleWartosci;
		}
	}
}

void Pole::wykonajTure(class GUI * Window)
{
	wykonajTurePrzejsciePierwsze(Window);
	wykonajTurePrzejscieDrugie();
}
