#include "Scope.h"
#include "Pole.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>


Scope::Scope(QWidget *parent, Pole * input)
	: QMainWindow(parent)
{
	Field = input;
	ui.setupUi(this);
	connect(ui.ShowButton, SIGNAL(released()), this, SLOT(ShowCell()));
	connect(ui.CloseButton, SIGNAL(released()), this, SLOT(CloseMe()));
}

void Scope::ShowCell()
{
	int x = 0;
	int y = 0;
	QString tmp = ui.xPosText->toPlainText();
	x = tmp.toInt();
	tmp = "\0";

	tmp = ui.yPosText->toPlainText();
	y = tmp.toInt();
	tmp = "\0";
	QString output;
	for (int i = 0; i < Field->plansza[x][y].iloscWartosci;i++)
	{
		output += QString::number(i);
		output += +": ";
		output += QString::number(Field->plansza[x][y].wartosci[i]);
		output += "\n";
	}

	ui.ValuesText->document()->setPlainText(output);
}

void Scope::CloseMe()
{
	emit finished();
}