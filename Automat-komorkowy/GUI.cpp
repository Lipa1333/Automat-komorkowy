﻿#include "GUI.h"
#include "Configure.h"
#include "Generate.h"
#include "Scope.h"
#include "Baza.h"
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
	connect(ui.SaveValueButton, SIGNAL(released()), this, SLOT(Edit()));
	connect(ui.ScopeButton, SIGNAL(released()), this, SLOT(NewScope()));
	connect(ui.LoadScriptButton, SIGNAL(released()), this, SLOT(LoadScript()));
	connect(ui.SaveScriptButton, SIGNAL(released()), this, SLOT(ExecuteScript()));
	connect(ui.NextIncButton, SIGNAL(released()), this, SLOT(NextInc()));
	connect(ui.PrevIncButton, SIGNAL(released()), this, SLOT(PrevInc()));
	connect(worker, SIGNAL(finished()), this, SLOT(Redraw()));
	connect(thread, SIGNAL(started()), worker, SLOT(process()));
	ui.verticalScrollBar->setTracking(true);
	ui.horizontalScrollBar->setTracking(true);
	connect(ui.verticalScrollBar, SIGNAL(sliderReleased()), this, SLOT(Redraw()));
	connect(ui.horizontalScrollBar, SIGNAL(sliderReleased()), this, SLOT(Redraw()));
	connect(ui.verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(Redraw(int)));
	connect(ui.horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(Redraw(int)));
	connect(ui.ConfigButton, SIGNAL(released()), this, SLOT(BeginConfig()));
	connect(ConfigureWindow, SIGNAL(finished()), this, SLOT(FinishConfig()));
	thread->start();
	ui.SaveValueButton->setEnabled(false);
	ui.ConfigButton->setEnabled(false);
	
	for (int i = 0; i < 6; i++)
	{
		Colors[i] = 0;
	}
}

GUI::~GUI()
{
	thread->terminate();
}

void GUI::paintEvent(QPaintEvent *event)
{
	QString xCoord, yCoord;
	QPainter painter;
	if (Field != NULL)
	{
		uint32_t r, g, b, a, value;
		r = g = b = 0;
		int tmp = ui.horizontalScrollBar->value();
		painter.begin(this);
		if (oversized)
		{
			for (int x = 0; x <= 11; x++)
			{
				for (int y = 0; y <= 11; y++)
				{
					// Make filling
					if (Colors[0] >= 0)
					{
						r = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[0]];
					}
					else r = 0;

					if (Colors[1] >= 0)
					{
						g = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[1]];
					}
					else g = 0;

					if (Colors[2] >= 0)
					{
						b = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[2]];
					}
					else b = 0;

					painter.fillRect(110 + (32 * x), 10 + (32 * y), 32, 32, QColor(r, g, b, 255));
					r = g = b = 0;
					// Make borders
					if (Colors[3] >= 0)
					{
						r = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[4]];
					}
					else r = 0;

					if (Colors[4] >= 0)
					{
						g = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[5]];
					}
					else g = 0;

					if (Colors[5] >= 0)
					{
						b = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[6]];
					}
					else b = 0;

					painter.fillRect(110 + (32 * x), 10 + (32 * y), 5, 32, QColor(r, g, b, 255));
					painter.fillRect(110 + (32 * x) + 27, 10 + (32 * y), 5, 32, QColor(r, g, b, 255));

					painter.fillRect(110 + (32 * x) + 5, 10 + (32 * y), 22, 5, QColor(r, g, b, 255));
					painter.fillRect(110 + (32 * x) + 5, 10 + (32 * y) + 27, 22, 5, QColor(r, g, b, 255));
					r = g = b = 0;
				}
			}
		}
		else
		{
			for (int x = 0; x < Field->rozmiar; x++)
			{
				for (int y = 0; y < Field->rozmiar; y++)
				{
					// Make filling
					if (Colors[0] >= 0)
					{
						r = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[0]];
					}
					else r = 0;

					if (Colors[1] >= 0)
					{
						g = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[1]];
					}
					else g = 0;

					if (Colors[2] >= 0)
					{
						b = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[2]];
					}
					else b = 0;
					painter.fillRect(110 + (32 * x), 10 + (32 * y), 32, 32, QColor(r, g, b, 255));
					r = g = b = 0;
					// Make borders
					if (Colors[3] >= 0)
					{
						r = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[3]];
					}
					else r = 0;

					if (Colors[4] >= 0)
					{
						g = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[4]];
					}
					else g = 0;

					if (Colors[5] >= 0)
					{
						b = Field->plansza[x + ui.horizontalScrollBar->value()][y + ui.verticalScrollBar->value()].wartosci[Colors[5]];
					}
					else b = 0;

					painter.fillRect(110 + (32 * x), 10 + (32 * y), 5, 32, QColor(r, g, b, 255));
					painter.fillRect(110 + (32 * x)+27, 10 + (32 * y), 5, 32, QColor(r, g, b, 255));

					painter.fillRect(110 + (32 * x), 10 + (32 * y), 32, 5, QColor(r, g, b, 255));
					painter.fillRect(110 + (32 * x), 10 + (32 * y) + 27, 32, 5, QColor(r, g, b, 255));
					r = g = b = 0;
				}
			}
		}
	}

	if (ui.StepSaveButton->checkState())
	{
		string name = std::to_string(incrementation) + ".txt";
		Baza::zapisz(name, *Field);
		incrementation++;
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
	ui.LoadScriptButton->setEnabled(false);
	ui.SaveScriptButton->setEnabled(false);
}

void GUI::StopSimulation()
{
	simulate = false;
	ui.StopButton->setEnabled(false);
	ui.StartButton->setEnabled(true);
	ui.StepButton->setEnabled(true);
	ui.LoadScriptButton->setEnabled(true);
	ui.SaveScriptButton->setEnabled(true);
}

void GUI::Redraw()
{
	this->repaint();
}

void GUI::Redraw(int value)
{
	this->repaint();
}

void GUI::Step()
{
	step = true;
}

void GUI::Save()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save file"), "",
		tr("Text file (*.txt);;All Files (*)"));

	if (fileName.isEmpty()) return;
	Baza::zapisz(fileName.toStdString(), *Field);
}

void GUI::Load()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Load file"), "",
		tr("Text file (*.txt);;All Files (*)"));

	if (fileName.isEmpty()) return;

	if (Field != NULL)
	{
		delete(Field);
	}
	Baza::wczytaj(fileName.toStdString(), Field);

	string name = path = fileName.toStdString();
	name.resize(name.find("."));
	name = name.substr(name.find_last_of("/") + 1);

	char* p;
	strtol(name.c_str(), &p, 10);

	if (*p == 0)
	{
		incrementation = stoi(name);
		string pathToFile = path;
		string extenstion = pathToFile.substr(path.find_last_of("."));
		pathToFile = pathToFile.substr(0,pathToFile.find_last_of("/")+1);

		if (incrementation == 0)
		{
			string fileExists = pathToFile + std::to_string(incrementation + 1) + extenstion;
			ifstream f(fileExists.c_str());
			if (f.good())
			{
				ui.NextIncButton->setEnabled(true);
			}
		}
		else
		{
			string fileExists = pathToFile + std::to_string(incrementation + 1) + extenstion;
			ifstream f(fileExists.c_str());
			if (f.good())
			{
				ui.NextIncButton->setEnabled(true);
			}

			fileExists = pathToFile + std::to_string(incrementation - 1) + extenstion;
			ifstream g(fileExists.c_str());
			if (g.good())
			{
				ui.PrevIncButton->setEnabled(true);
			}
		}

	}

	if (Field->plansza.size() >= 12)
	{
		oversized = true;
		ui.verticalScrollBar->setMaximum(Field->plansza.size() - 12);
		ui.horizontalScrollBar->setMaximum(Field->plansza.size() - 12);

	}
	else
	{
		oversized = false;
	}
	this->Redraw();
	if (Field != NULL && engine != NULL && program != NULL)
	{
		ui.StartButton->setEnabled(true);
		ui.StepButton->setEnabled(true);
	}
	ui.SaveValueButton->setEnabled(true);
	ui.SaveButton->setEnabled(true);
	worker->Field = Field;
}

void GUI::NewField()
{
	GenerateWindow = new Generate(this);
	GenerateWindow->show();
	connect(GenerateWindow, SIGNAL(finished()), this, SLOT(FieldFinished()));
}

void GUI::NewScope()
{
	ScopeWindow = new Scope(this, Field);
	ScopeWindow->show();
	connect(ScopeWindow, SIGNAL(finished()), this, SLOT(KillScope()));
}

void GUI::KillScope()
{
	ScopeWindow->close();
	ScopeWindow = NULL;
}

void GUI::FieldFinished()
{
	if (Field != NULL)
	{
		delete(Field);
		Field = NULL;
	}
	Field = GenerateWindow->Field;
	worker->Field = Field;
	GenerateWindow->close();
	if (Field->plansza.size() >= 12)
	{
		oversized = true;
		ui.verticalScrollBar->setMaximum(Field->plansza.size() - 12);
		ui.horizontalScrollBar->setMaximum(Field->plansza.size() - 12);

	}
	else
	{
		oversized = false;
	}

	ui.SaveValueButton->setEnabled(true);
	ui.SaveButton->setEnabled(true);
	ui.ConfigButton->setEnabled(true);
}

void GUI::Edit()
{
	int xpos = -1;
	int ypos = -1;
	int varNum = -1;
	float value = 0;

	QString tmp = ui.xPosEditText->toPlainText();
	xpos = tmp.toInt();
	tmp = "\0";

	tmp = ui.yPosEditText->toPlainText();
	ypos = tmp.toInt();
	tmp = "\0";

	tmp = ui.VarNumText->toPlainText();
	varNum = tmp.toInt();
	tmp = "\0";

	tmp = ui.ValueEditText->toPlainText();
	value = tmp.toFloat();
	tmp = "\0";

	if (xpos < 0 || ypos < 0 || varNum < 0 || xpos >= Field->rozmiar, ypos >= Field->rozmiar || varNum >= Field->plansza[0][0].iloscWartosci)
	{
		return;
	}

	Field->plansza[xpos][ypos].wartosci[varNum] = value;

	Redraw();
}

void GUI::ExecuteScript()
{
	if (program != NULL)
	{
		delete(program);
	}
	program = new QScriptProgram(ui.ScriptText->toPlainText());
	if (engine != NULL)
	{
		delete(engine);
	}
	engine = new QScriptEngine();
	QScriptSyntaxCheckResult res = engine->checkSyntax(ui.ScriptText->toPlainText());
	switch (res.state())
	{
	case 0:
		ui.ScriptLabel->setText("Script Status: The script contains a syntax error");
		break;
	case 1:
		ui.ScriptLabel->setText("Script Status: The script is incomplete");
		break;
	case 2:
		ui.ScriptLabel->setText("Script Status: Correct");
		if (Field != NULL && engine != NULL && program != NULL)
		{
			ui.StartButton->setEnabled(true);
			ui.StepButton->setEnabled(true);
		}
		break;

	default:
		break;
	}
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

void GUI::PrevInc()
{
	string pathToFile = path;
	string extenstion = pathToFile.substr(path.find_last_of("."));
	pathToFile = pathToFile.substr(0, pathToFile.find_last_of("/") + 1);
	incrementation--;
	Baza::wczytaj(pathToFile + std::to_string(incrementation) + extenstion, Field);

	string fileExists = pathToFile + std::to_string(incrementation - 1) + extenstion;
	ifstream f(fileExists.c_str());
	if (!f.good())
	{
		ui.PrevIncButton->setEnabled(false);
	}
	ui.NextIncButton->setEnabled(true);
	Redraw();

}

void GUI::NextInc()
{
	string pathToFile = path;
	string extenstion = pathToFile.substr(path.find_last_of("."));
	pathToFile = pathToFile.substr(0, pathToFile.find_last_of("/") + 1);
	incrementation++;
	Baza::wczytaj(pathToFile + std::to_string(incrementation) + extenstion, Field);

	string fileExists = pathToFile + std::to_string(incrementation + 1) + extenstion;
	ifstream f(fileExists.c_str());
	if (!f.good())
	{
		ui.NextIncButton->setEnabled(false);
	}
	ui.PrevIncButton->setEnabled(true);
	Redraw();
}

void GUI::BeginConfig()
{
	ConfigureWindow = new Configure(this);
	connect(ConfigureWindow, SIGNAL(finish()), this, SLOT(FinishConfig()));
	ConfigureWindow->show();
}

void GUI::FinishConfig()
{
	for (int i = 0; i < 6; i++)
	{
		Colors[i] = ConfigureWindow->Colors[i];
		if (Colors[i] >= this->Field->plansza[0][0].iloscWartosci) Colors[i] = -1;
	}
	ConfigureWindow->close();
	delete(ConfigureWindow);
}