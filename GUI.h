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

	bool simulate = false;
	bool step = false;
	bool ready = true;
	bool oversized = false;
	int data = 10;

	QScriptEngine * engine = NULL;
	QScriptProgram * program = NULL;

	QThread * thread = NULL;
	class Worker * worker = NULL;
	Pole * Field = NULL;

	class Generate * GenerateWindow = NULL;
	class Scope * ScopeWindow = NULL;
private slots:

	void StartSimulation();
	void StopSimulation();
	void Save();
	void Load();
	void Step();
	void Redraw();
	void NewField();
	void FieldFinished();
	void Edit();
	void LoadScript();
	void ExecuteScript();
	void NewScope();
	void KillScope();

private:
	Ui::GUIClass ui;
};
