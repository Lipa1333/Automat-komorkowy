#pragma once
#include <list>
#include "Komorka.h"
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
	void static zapisz(string nazwa_pliku, Pole pole);
	void static wczytaj(string nazwa_pliku, Pole * pole);

};
