#include "stdafx.h"
#pragma once
#include "Komorka.h"
#include "Pole.h"
#include "Baza.h"
#include <fstream>

#include <list>
#include <iostream>
#include <cstddef>

using namespace std;

void operator<<(std::ostream& os, const vector<float>& v)
{
	for (vector<float>::const_iterator i = v.begin(); i != v.end(); ++i) {
		os << *i << " , ";
	}
	os << endl;
}

void operator<<(std::ostream& os, vector<Komorka *>& v)
{
	for (vector<Komorka *>::iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it;
	}
	os << endl;
}

void operator<<(std::ostream& os, Komorka& v)
{
	os << v.czyAgent << endl;
	os << v.przyszleWartosci;
	os << endl;
	os << v.wartosci;
	os << endl;
}

void operator<<(std::ostream& os, vector<Komorka>& v)
{
	for (vector<Komorka>::iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it;
	}
	os << endl;
}


void operator<<(std::ostream& os, vector<vector<Komorka>>& v)
{
	for (vector<vector<Komorka>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it;
	}
	os << endl;
}

void Baza::zapisz(string nazwa_pliku, Komorka lista[], Pole pole)//Pole pole, Komorka lista[]
{
	fstream plik(nazwa_pliku, ios::out);
	if (plik.good())
	{
		plik << "Pole:" << endl;
		plik << "\tplansza: " << pole.plansza;
		plik << "\tlistaAktywnychKomorek: " << pole.listaAktywnychKomorek;

		for (int licznik=0; licznik < sizeof(lista); licznik++)
		{
			plik << "Komorka:" << endl;
			plik << "\tczyAgent: " << lista[licznik].czyAgent << endl;
			plik << "\tiloscWartosci: " << lista[licznik].iloscWartosci << endl;
			plik << "\twartosci: " << lista[licznik].wartosci;
			plik << "\tprzyszleWartosci: " << lista[licznik].przyszleWartosci;
		}

		plik.close();
	}else
	{
		cout << "Blad przy probie zpisu do YAML!" << endl;
	}
}
