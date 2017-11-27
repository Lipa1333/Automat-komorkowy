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
	void borderCheckClassic(bool checked);
	void borderCheckFloat(bool checked);
	void NeighborsCheckMoore(bool checked);
	void NeighborsCheckVon(bool checked);

signals:
	void finished();

private:
	Ui::Generate ui;
};
