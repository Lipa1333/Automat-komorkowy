#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Editor.h"
#include "Pole.h"

class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(Pole * input, QWidget *parent = Q_NULLPTR);
	Pole * Field;
	private slots:

	void Edit();
	void Shutdown();


private:
	Ui::EditorWindow ui;
};
