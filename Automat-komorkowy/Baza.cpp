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
	os << "[ ";
	for (vector<float>::const_iterator i = v.begin(); i != v.end(); ++i) {
		if (i+1 == v.end())
		{
			os << *i;
		}else
		{
			os << *i << " , ";
		}
	}
	os << " ]" << endl;
}

void operator<<(std::ostream& plik, Komorka& v)
{
	plik << "\tKomorka:" << endl;
	plik << "\t\tczyAgent: " << v.czyAgent << endl;
	plik << "\t\tiloscWartosci: " << v.iloscWartosci << endl;
	plik << "\t\twartosci: " << v.wartosci;
	plik << "\t\tprzyszleWartosci: " << v.przyszleWartosci;
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

void Baza::zapisz(string nazwa_pliku, Pole pole)
{
	fstream plik(nazwa_pliku, ios::out);
	if (plik.good())
	{
		plik << "Pole:" << endl;
		plik << "\trozmiar: " << pole.rozmiar;
		plik << endl;
		plik << "Komorki:" << endl;
		plik << pole.plansza;
		plik.close();
	}else
	{
		cout << "Blad przy probie zpisu do YAML!" << endl;
	}
}


void Baza::wczytaj(string nazwa_pliku)
{
	fstream plik(nazwa_pliku, ios::in);
	if (plik.good())
	{
		// kod
	}
	else
	{
		cout << "Blad przy probie odczytu do YAML!" << endl;
	}
}
