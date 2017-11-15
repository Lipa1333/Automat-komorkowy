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