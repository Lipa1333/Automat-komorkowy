#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Worker.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);

	void paintEvent(QPaintEvent *event);

	bool Simulate = false;
	int data = 10;

	QThread * thread;
	Worker * worker;

private slots:

	void StartSimulation();
	void StopSimulation();
	void Save();
	void Load();
	void Step();
	void Redraw();

private:
	Ui::GUIClass ui;
};
