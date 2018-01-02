#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Generate.h"
#include "Pole.h"

class Generate : public QMainWindow
{
	Q_OBJECT

public:
	Generate(QWidget *parent = Q_NULLPTR);
	//! Variable for storing and passing created field
	Pole * Field;
private slots:

	//! Function creates a field of cells and sends signal finished()
	void Create();
	//! Function checking boolean value for borders type
	void borderCheckClassic(bool checked);
	//! Function checking exclusive boolean value for borders type
	void borderCheckFloat(bool checked);
	//! Function checking exclusive boolean value for neighbors type
	void NeighborsCheckMoore(bool checked);
	//! Function checking exclusive boolean value for neighbors type
	void NeighborsCheckVon(bool checked);

signals:
	void finished();

private:
	Ui::Generate ui;
};
