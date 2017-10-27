
#include "Pole.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUI w;
	w.show();
	return a.exec();

}


/*
TODO: 
Enable evolution.
Enable Coloring
Enable Scrolling
*/