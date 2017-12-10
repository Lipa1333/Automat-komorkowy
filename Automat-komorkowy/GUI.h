#pragma once

#include <QtWidgets/QMainWindow>
#include <QtScript/QScriptProgram>
#include <QScriptEngine>
#include "ui_GUI.h"
#include "Worker.h"
#include "Pole.h"
#include "Generate.h"
#include "Scope.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);

	void paintEvent(QPaintEvent *event);

	//! Variable controling simulation process
	bool simulate = false;
	//! Variable controling type of simulation
	bool step = false;
	//! Variable giving access to continue simulation
	bool ready = true;
	//! Variable for defining type of visualization
	bool oversized = false;

	QScriptEngine * engine = NULL;
	QScriptProgram * program = NULL;

	QThread * thread = NULL;
	class Worker * worker = NULL;
	Pole * Field = NULL;

	class Generate * GenerateWindow = NULL;
	class Scope * ScopeWindow = NULL;
private slots:
	//! Function allowing simulation to start in other thread
	void StartSimulation();
	//! Function  stopping simulation in other thread
	void StopSimulation();
	//! Function calling save functionality
	void Save();
	//! Function calling load functionality
	void Load();
	//! Function allowing simulation to progress a single step
	void Step();
	//! Function redrawing cells on GUI
	void Redraw();
	//! Function redrawing cells on GUI
	void Redraw(int value);
	//! Function starting creation of new field of cells
	void NewField();
	//! Function finishing and gaining newly created field
	void FieldFinished();
	//! Function editing a single value of cell
	void Edit();
	//! Function loading script from file and printing it in a text box
	void LoadScript();
	//! Function checking integrity of script and passing it to execution
	void ExecuteScript();
	//! Function for visualizing values in the cell
	void NewScope();
	//! Function ending visualization of values in the cell
	void KillScope();

private:
	Ui::GUIClass ui;
};
