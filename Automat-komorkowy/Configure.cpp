#include "Configure.h"
#include "GUI.h"
#include <QFileDialog>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>
#include <QTextStream>
#include <QScriptEngine>
#include <QScriptSyntaxCheckResult>
#include <iostream>
#include <fstream>

Configure::Configure(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.DoneButton, SIGNAL(released()), this, SLOT(FinishConfigure()));
}

void Configure::FinishConfigure()
{
	bool ok;
	QString InnerR = ui.InnerR->toPlainText();
	QString InnerG = ui.InnerG->toPlainText();
	QString InnerB = ui.InnerB->toPlainText();
	QString OuterR = ui.OuterR->toPlainText();
	QString OuterG = ui.OuterG->toPlainText();
	QString OuterB = ui.OuterB->toPlainText();

	int value = InnerR.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[0] = value;
	}
	value = -1;
	ok = false;
	
	value = InnerG.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[1] = value;
	}
	value = -1;
	ok = false;

	value = InnerB.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[2] = value;
	}
	value = -1;
	ok = false;

	value = OuterR.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[3] = value;
	}
	value = -1;
	ok = false;

	value = OuterG.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[4] = value;
	}
	value = -1;
	ok = false;

	value = OuterB.toInt(&ok);
	if (ok && value >= 0)
	{
		Colors[5] = value;
	}
	value = -1;
	ok = false;


	emit finish();
}