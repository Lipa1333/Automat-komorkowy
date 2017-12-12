#pragma once
#include "Komorka.h"
#include "Pole.h"
#include "Baza.h"
#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string removeSpaces(string input)
{
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	return input;
}

void operator<<(std::ostream& os, const vector<float>& v)
{
	os << "[";
	for (vector<float>::const_iterator i = v.begin(); i != v.end(); ++i) {
		if (i+1 == v.end())
		{
			os << *i;
		}else
		{
			os << *i << ",";
		}
	}
	os << "]" << endl;
}

void operator<<(std::ostream& plik, Komorka& v)
{
	plik << "\tKomorka_wartosci: " << v.wartosci;
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
		plik << "Informacje:" << endl;
		plik << "\trozmiar: " << pole.rozmiar;
		plik << endl;
		plik << "\tiloscWartosci: " << pole.plansza[0][0].iloscWartosci; // Pobieram ilość wartości z pierwszej(zerowej) komórki w vektorze
		plik << endl;
		plik << "\tczyMoorea: " << pole.czyMoorea;
		plik << endl;
		plik << "\tczyPrzeplywajace: " << pole.czyPrzeplywajace;
		plik << endl;
		plik << "Komorki:" << endl;
		plik << pole.plansza;
		plik.close();
	}else
	{
		cout << "Blad przy probie zpisu do YAML!" << endl;
	}
}


void Baza::wczytaj(string nazwa_pliku, Pole * pole)
{
	string informacje;
	string rozmiar;
	string komorki;
	string czyMoorea;
	string czyPrzeplywajace;
	bool czyMoorea_bool;
	bool czyPrzeplywajace_bool;
	int rozmiar_int;
	int iloscWartosci_int;
	string iloscWartosci;
	fstream plik(nazwa_pliku, std::ios::in | std::ios::out);
	if (plik.good())
	{
		getline(plik, informacje); // 1 linia

		getline(plik, rozmiar); // 2 linia
		rozmiar.erase(std::remove(rozmiar.begin(), rozmiar.end(), '\t'), rozmiar.end());
		rozmiar = rozmiar.substr(9);
		std::stringstream ss;
		ss << rozmiar;
		ss >> rozmiar_int;
		cout << "R:" << rozmiar_int << endl;

		getline(plik, iloscWartosci); // 3 linia
		iloscWartosci.erase(std::remove(iloscWartosci.begin(), iloscWartosci.end(), '\t'), iloscWartosci.end());
		iloscWartosci = iloscWartosci.substr(15);
		std::stringstream ss_iw;
		ss_iw << iloscWartosci;
		ss_iw >> iloscWartosci_int;
		cout << "IW: " << iloscWartosci_int << endl;

		getline(plik, czyMoorea); // 4 linia
		czyMoorea.erase(std::remove(czyMoorea.begin(), czyMoorea.end(), '\t'), czyMoorea.end());
		czyMoorea = czyMoorea.substr(11);
		std::stringstream ss_cm;
		ss_cm << czyMoorea;
		ss_cm >> czyMoorea_bool;
		cout << "czyMoorea_bool: " << czyMoorea_bool << endl;

		getline(plik, czyPrzeplywajace); // 5 linia
		czyPrzeplywajace.erase(std::remove(czyPrzeplywajace.begin(), czyPrzeplywajace.end(), '\t'), czyPrzeplywajace.end());
		czyPrzeplywajace = czyPrzeplywajace.substr(17);
		std::stringstream ss_cp;
		ss_cp << czyPrzeplywajace;
		ss_cp >> czyPrzeplywajace_bool;
		cout << "czyPrzeplywajace_bool: " << czyPrzeplywajace_bool << endl;

		getline(plik, komorki); // 7 linia
		cout << komorki << endl;

		pole->rozmiar = rozmiar_int;
		pole->czyMoorea = czyMoorea_bool;
		pole->czyPrzeplywajace = czyPrzeplywajace_bool;


		if (komorki == "Komorki:")
		{
			string linia1;
			int x = 0;
			int y = 0;
			int z = 0;
			while (!plik.eof())
			{
				getline(plik, linia1); // np. Komorka_wartosci: [1,0]
				/*
				if (!linia1.empty())
				{
					Komorka k;

					linia1.erase(std::remove(linia1.begin(), linia1.end(), '\t'), linia1.end());
					linia1 = linia1.substr(18);
					linia1 = linia1.substr(1, linia1.length() - 2);

					stringstream s2;
					s2 << linia1;
					double wartosc;
					char przecinek;
					cout << linia1 << "   Wartosci: ";

					int z = 0;
					if (y == rozmiar_int - 1)
					{
						y = 0;
					}
					while (s2 >> wartosc)
					{
						cout << wartosc << " | ";
						s2 >> przecinek;
						pole->plansza[x][y].wartosc[z] = wartosc;
						z++;
					}
					cout << endl;
					pole->plansza[x][y].iloscWartosci = iloscWartosci_int;
					y++;
				}
				x++;
				*/
				if (!linia1.empty())
				{

					linia1.erase(std::remove(linia1.begin(), linia1.end(), '\t'), linia1.end());
					linia1 = linia1.substr(18);
					linia1 = linia1.substr(1, linia1.length() - 2);

					stringstream s2;
					s2 << linia1;
					double wartosc;
					char przecinek;
					cout << linia1 << "   Wartosci: ";


					if (y > rozmiar_int - 1)
					{
						y = 0;
						x++;
					}
					if (z > iloscWartosci_int - 1)
					{
						z = 0;
					}
					while (s2 >> wartosc)
					{
						cout << wartosc << " | " << x << ":" << y << ":" << z << "\t";
					
						s2 >> przecinek;
						pole->plansza[x][y].wartosc[z] = wartosc;
						z++;
					}
					pole->plansza[x][y].iloscWartosci = iloscWartosci_int;
					y++;
					cout << endl;
				}
			}
		}
		plik.close();



	}
	else
	{
		cout << "Blad przy probie odczytu do YAML!" << endl;
	}
}
