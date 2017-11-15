#include "Editor.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>


Editor::Editor(Pole * input, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Field = input;
	connect(ui.SaveButton, SIGNAL(released()), this, SLOT(Edit()));
	connect(ui.CloseButton, SIGNAL(released()), this, SLOT(Shutdown()));
}

void Editor::Edit()
{
	int xpos = -1;
	int ypos = -1;
	int varNum = -1;
	int value = 0;

	QString tmp = ui.xText->toPlainText();
	xpos = tmp.toInt();
	tmp = "\0";

	tmp = ui.yText->toPlainText();
	ypos = tmp.toInt();
	tmp = "\0";

	tmp = ui.variableText->toPlainText();
	varNum = tmp.toInt();
	tmp = "\0";

	tmp = ui.valueText->toPlainText();
	value = tmp.toInt();
	tmp = "\0";

	if (xpos < 0 || ypos < 0 || varNum < 0 || xpos >= Field->rozmiar, ypos >= Field->rozmiar || varNum >= Field->plansza[0][0].iloscWartosci)
	{
		return;
	}

	Field->plansza[xpos][ypos].wartosci[varNum] = value;
}

void Editor::Shutdown()
{
	this->close();
}