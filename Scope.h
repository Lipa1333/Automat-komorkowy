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
	//! Variable containing pointer to Field
	Pole * Field;

private slots:
	//! Function showing values of the cell
	void ShowCell();
	//! Function closing a scope
	void CloseMe();

signals:
	void finished();

private:
	Ui::MainWindow ui;
};
