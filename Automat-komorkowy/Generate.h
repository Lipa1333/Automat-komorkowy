#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Generate.h"
#include "Pole.h"

class Generate : public QMainWindow
{
	Q_OBJECT

public:
	Generate(QWidget *parent = Q_NULLPTR);
	Pole * Field;
private slots:

	void Create();

signals:
	void finished();

private:
	Ui::Generate ui;
};
