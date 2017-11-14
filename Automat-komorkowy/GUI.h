#pragma once

#include <QtWidgets/QMainWindow>
#include <QtScript/QScriptProgram>
#include "ui_GUI.h"
#include "Worker.h"
#include "Pole.h"
#include "Generate.h"
#include "Editor.h"

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

	QScriptProgram * program = NULL;

	QThread * thread = NULL;
	Worker * worker = NULL;
	Pole * Field = NULL;

	Generate * GenerateWindow = NULL;
	Editor * EditorWindow = NULL;
private slots:

	void StartSimulation();
	void StopSimulation();
	void Save();
	void Load();
	void Step();
	void Redraw();
	void NewField();
	void FieldFinished();
	void EditorSpawn();
	void LoadScript();
	void ExecuteScript();

private:
	Ui::GUIClass ui;
};
