#pragma once
#include <list>
#include "Pole.h"
using namespace std;

string removeSpaces(string input);
void operator<<(std::ostream& os, const vector<float>& v);
void operator<<(std::ostream& plik, Komorka& v);
void operator<<(std::ostream& os, vector<Komorka>& v);
void operator<<(std::ostream& os, vector<vector<Komorka>>& v);

class  Baza
{
public:
	//! Save funtion creating file and filling if based on Pole provided in argument
	void static zapisz(string nazwa_pliku, Pole pole);
	//! Load function creating new field based on data provided in file under nazwa_pliku.
	void static wczytaj(string nazwa_pliku, Pole *& pole);

};
