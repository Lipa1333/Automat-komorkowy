#pragma once
#include <list>
#include "Pole.h"
using namespace std;
/*!
Metoda która usuwa spacje ze stringa podanego w argumencie,
zwraca nowego stringa bez spacji 
*/
string removeSpaces(string input);

//! Operator pisania do strumienia, zapisuje wartiœci komórki w []
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
	Metoda s³u¿¹ca do zpaisu aktualnego stanu planszy
	Argumenty to: nazwa_pliku - nazwa pliku do zapisu, 
				  pole - dane do zpaisu pliku
	Przyk³adowy zapis:

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
	Metoda s³u¿¹ca do odczytu stanu planszy
	Argumenty to: nazwa_pliku - nazwa pliku z którego pobierane s¹ dane, 
				  pole - wskaŸnik do którego dane bêd¹ wczytywane
	Przyk³adowy plik do odczytu:

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
