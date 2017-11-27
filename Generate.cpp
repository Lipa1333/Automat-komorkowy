#include "Generate.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>


Generate::Generate(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.FloatBox->setChecked(true);
	ui.MooreBox->setChecked(true);
	connect(ui.GenerateButton, SIGNAL(released()), this, SLOT(Create()));
	connect(ui.MooreBox, SIGNAL(toggled(bool)), this, SLOT(NeighborsCheckMoore(bool)));
	connect(ui.VonBox, SIGNAL(toggled(bool)), this, SLOT(NeighborsCheckVon(bool)));
	connect(ui.ClassicBox, SIGNAL(toggled(bool)), this, SLOT(borderCheckClassic(bool)));
	connect(ui.FloatBox, SIGNAL(toggled(bool)), this, SLOT(borderCheckFloat(bool)));
}

void Generate::Create()
{
	QString Size = ui.SizeText->toPlainText();
	QString Variables = ui.VariableText->toPlainText();
	int size_int = 0;
	size_int = Size.toInt();
	int variable_int = 0;
	variable_int = Variables.toInt();

	if (size_int == 0)
	{
		size_int = 10;
	}
	if (variable_int == 0)
	{
		variable_int = 1;
	}

	Field = new Pole(size_int, ui.MooreBox->isChecked(), variable_int, ui.FloatBox->isChecked());
	emit finished();

}

void Generate::NeighborsCheckMoore(bool checked)
{
	ui.VonBox->setChecked(!ui.MooreBox->isChecked());
}

void Generate::NeighborsCheckVon(bool checked)
{
	ui.MooreBox->setChecked(!ui.VonBox->isChecked());
}

void Generate::borderCheckClassic(bool checked)
{
	ui.FloatBox->setChecked(!ui.ClassicBox->isChecked());
}

void Generate::borderCheckFloat(bool checked)
{
	ui.ClassicBox->setChecked(!ui.FloatBox->isChecked());
}