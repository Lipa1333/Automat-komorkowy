
#include "Pole.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <iostream>

int Komorka::iloscWartosci = 0;
std::vector<float>(*Komorka::dzialanie)(std::vector<float> v, std::vector<std::vector<float>> n) = NULL;

bool Komorka::czyPrzeplywajace = false;

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	GUI w;
	w.show();
	return a.exec();

}


