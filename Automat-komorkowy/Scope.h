#pragma once

#include <QtWidgets/QMainWindow>
#include <QtScript/QScriptProgram>
#include "ui_Scope.h"
#include "Pole.h"

class Scope : public QMainWindow
{
	Q_OBJECT

public:
	Scope(QWidget *parent = Q_NULLPTR, Pole * input = NULL);
	Pole * Field;

private slots:
	void ShowCell();
	void CloseMe();

signals:
	void finished();

private:
	Ui::MainWindow ui;
};
