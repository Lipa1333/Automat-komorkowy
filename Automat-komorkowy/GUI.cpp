#include "GUI.h"
#include "Generate.h"
#include "Editor.h"
#include <QFileDialog>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>
#include <QTextStream>
#include <iostream>
#include <fstream>

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.StepButton->setEnabled(false);
	ui.StartButton->setEnabled(false);
	ui.StopButton->setEnabled(false);
	ui.SaveButton->setEnabled(false);

	connect(ui.StopButton, SIGNAL(released()), this, SLOT(StartSimulation()));
	connect(ui.StepButton, SIGNAL(released()), this, SLOT(Step()));
	connect(ui.SaveButton, SIGNAL(released()), this, SLOT(Save()));
	connect(ui.LoadButton, SIGNAL(released()), this, SLOT(Load()));
	connect(ui.NewButton, SIGNAL(released()), this, SLOT(NewField()));
	thread = new QThread();
	worker = new Worker(&simulate, &step, &ready, this);
	worker->moveToThread(thread);
	connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

	connect(ui.StopButton, SIGNAL(released()), this, SLOT(StopSimulation()));
	connect(ui.StartButton, SIGNAL(released()), this, SLOT(StartSimulation()));
	connect(ui.StepButton, SIGNAL(released()), this, SLOT(Step()));
	connect(ui.ShowButton, SIGNAL(released()), this, SLOT(Redraw()));
	connect(ui.EditButton, SIGNAL(released()), this, SLOT(EditorSpawn()));
	connect(ui.LoadScriptButton, SIGNAL(released()), this, SLOT(LoadScript()));
	connect(ui.SaveScriptButton, SIGNAL(released()), this, SLOT(ExecuteScript()));
	connect(worker, SIGNAL(finished()), this, SLOT(Redraw()));
	connect(thread, SIGNAL(started()), worker, SLOT(process()));
	thread->start();

}

void GUI::paintEvent(QPaintEvent *event)
{
	QString xCoord, yCoord;
	xCoord = ui.XCoordinateText->toPlainText();
	yCoord = ui.YCoordinateText->toPlainText();
	int xpos = -1;
	int ypos = -1;
	xpos = xCoord.toInt();
	ypos = yCoord.toInt();

	if (xpos < 0) xpos = 0;
	if (Field != NULL && xpos > Field->plansza.size() - 11) xpos = Field->plansza.size() - 12;
	if (ypos < 0) ypos = 0;
	if (Field != NULL && ypos > Field->plansza.size() - 11) ypos = Field->plansza.size() - 12;
	
	QPainter painter;
	if(Field != NULL)
	{
		uint32_t r, g, b, a, value;
		r = g = b = a = 0;
		painter.begin(this);
		if (oversized)
		{
			for (int x = 0; x <= 11; x++)
			{
				for (int y = 0; y <= 11; y++)
				{
					value = Field->plansza[x + xpos][y + ypos].wartosci[0];
					a = (value & 0x000000FF);
					b = (value & 0x0000FF00);
					b = b >> 8;
					g = (value & 0x00FF0000);
					g = g >> 16;
					r = (value & 0xFF000000);
					r = r >> 24;
					painter.fillRect(110 + (32 * x), 10 + (32 * y), 32, 32, QColor(r, g, b, a));
				}
			}
		}
		else
		{
			for (int x = 0; x < Field->rozmiar; x++)
			{
				for (int y = 0; y < Field->rozmiar; y++)
				{
					value = Field->plansza[x][y].wartosci[0];
					a = (value & 0x000000FF);
					b = (value & 0x0000FF00);
					b = b >> 8;
					g = (value & 0x00FF0000);
					g = g >> 16;
					r = (value & 0xFF000000);
					r = r >> 24;
					painter.fillRect(110 + (32 * x), 10 + (32 * y), 32, 32, QColor(r, g, b, a));
				}
			}
		}
	}
	QWidget::paintEvent(event);
	painter.end();
	ready = true;
}

void GUI::StartSimulation()
{
	simulate = true;
	ui.StopButton->setEnabled(true);
	ui.StartButton->setEnabled(false);
	ui.StepButton->setEnabled(false);
}

void GUI::StopSimulation()
{
	simulate = false;
	ui.StopButton->setEnabled(false);
	ui.StartButton->setEnabled(true);
	ui.StepButton->setEnabled(true);
}

void GUI::Redraw()
{
	this->repaint();
}

void GUI::Step()
{
	step = true;
}

void GUI::Save()
{
	/*TODO*/
}

void GUI::Load()
{
	/*TODO*/
}

void GUI::NewField()
{
	GenerateWindow = new Generate(this);
	GenerateWindow->show();
	connect(GenerateWindow, SIGNAL(finished()), this, SLOT(FieldFinished()));
}

void GUI::FieldFinished()
{
	Field = GenerateWindow->Field;
	worker->Field = Field;
	GenerateWindow->close();
	oversized = Field->plansza.size() >= 12;


	for (int x = 0; x < Field->plansza.size(); x++)
	{
		for (int y = 0; y < Field->plansza.size(); y++)
		{
			Field->plansza[x][y].wartosci[0] = 0x000000FF + 10* x + 5 *y;
		}
	}

	ui.StepButton->setEnabled(true);
	ui.StartButton->setEnabled(true);
	ui.SaveButton->setEnabled(true);

}

void GUI::EditorSpawn()
{
	EditorWindow = new Editor(Field, this);
	EditorWindow->show();
}

void GUI::ExecuteScript()
{
	program = new QScriptProgram(ui.ScriptText->toPlainText());
}

void GUI::LoadScript()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Load File with script"), "",
		tr("Text file (*.txt);;All Files (*)"));
	std::string Script;
	std::string tmp;
	std::ifstream myReadFile;
	myReadFile.open(fileName.toStdString());
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) 
		{
			std::getline(myReadFile, tmp);
			Script += tmp + "\n";
		}
	}
	myReadFile.close();

	ui.ScriptText->document()->setPlainText(QString::fromStdString(Script));
}