﻿#pragma once
#include "Pole.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include "qscriptvalueiterator.h"

std::vector<float> RunScript(std::vector<float> cell, const std::vector<std::vector<float>> neighbors, GUI * Window)
{
	Window->engine->evaluate(*Window->program);
	//engine.evaluate(program);
	//QScriptValue global = engine.globalObject();
	QScriptValue global = Window->engine->globalObject();
	QScriptValue edit = global.property("edit");
	//QScriptValue v1 = qScriptValueFromSequence(&engine, cell);
	QScriptValue v1 = qScriptValueFromSequence(Window->engine, cell);
	QScriptValueList args;
	args.append(qScriptValueFromSequence(Window->engine, cell));
	for (int i = 0; i < neighbors.size(); i++)
	{
		args.append(qScriptValueFromSequence(Window->engine, neighbors[i]));
	}
	QScriptValue result = edit.call(QScriptValue(), args);
	if (!result.isArray())
	{
		return cell;
	}
	QScriptValueIterator it(result);
	for (int i = 0; i < cell.size(); i++)
	{
		it.next();
		cell[i] = it.value().toNumber();
	}
	return cell;
}



int Komorka::iloscWartosci = 0;
std::vector<float>(*Komorka::dzialanie)(std::vector<float> v, std::vector<std::vector<float>> n, GUI * Window) = RunScript;

bool Komorka::czyPrzeplywajace = false;


/*! \mainpage Cellular Automata by : Łukasz Miros, Maciej Matejuk, Tomasz Krzyczkowski, Jakub Kopka, Hubert Murawski
*
* \section intro_sec Introduction
*
* Cellular Automata created for a academic project with ability to run custom scripts made in JavaScript.
*
*
* \section features_sec Features
*
* Running custom made scripts 
* Create sripts in JavaScript
* Dynamic number of cells and values for each cell
* Iterating over multiple stages
*
*
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUI w;
	w.show();
	return a.exec();

}