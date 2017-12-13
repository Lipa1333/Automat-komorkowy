#pragma once
#include <list>
#include "Pole.h"
using namespace std;
/*!
Metoda kt�ra usuwa spacje ze stringa podanego w argumencie,
zwraca nowego stringa bez spacji 
*/
string removeSpaces(string input);

//! Operator pisania do strumienia, zapisuje warti�ci kom�rki w []
void operator<<(std::ostream& os, const vector<float>& v);

//! Operator pisania do strumienia
void operator<<(std::ostream& plik, Komorka& v);

//! Operator pisania do strumienia
void operator<<(std::ostream& os, vector<Komorka>& v);

//! Operator pisania do strumienia
void operator<<(std::ostream& os, vector<vector<Komorka>>& v);

class  Baza
{
public:

	/*!
	Metoda s�u��ca do zpaisu aktualnego stanu planszy
	Argumenty to: nazwa_pliku - nazwa pliku do zapisu, 
				  pole - dane do zpaisu pliku
	Przyk�adowy zapis:

	Informacje:
		rozmiar: 15
		iloscWartosci: 1
		czyMoorea: 1
		czyPrzeplywajace: 205
	Komorki:
		Komorka_wartosci: [0]
		Komorka_wartosci: [260]
		Komorka_wartosci: [265]
		...

	*/
	void static zapisz(string nazwa_pliku, Pole pole);

	/*!
	Metoda s�u��ca do odczytu stanu planszy
	Argumenty to: nazwa_pliku - nazwa pliku z kt�rego pobierane s� dane, 
				  pole - wska�nik do kt�rego dane b�d� wczytywane
	Przyk�adowy plik do odczytu:

	Informacje:
		rozmiar: 15
		iloscWartosci: 1
		czyMoorea: 1
		czyPrzeplywajace: 205
	Komorki:
		Komorka_wartosci: [0]
		Komorka_wartosci: [260]
		Komorka_wartosci: [265]
		...

	*/
	void static wczytaj(string nazwa_pliku, Pole * pole);

};
