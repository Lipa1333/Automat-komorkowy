#include "GUI.h"
#include "Generate.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <QAction>
#include <QThread>



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
	worker = new Worker(&Simulate, this);
	worker->moveToThread(thread);
	connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
	connect(ui.StartButton, SIGNAL(released()), worker, SLOT(process()));
	connect(worker, SIGNAL(finished()), this, SLOT(Redraw()));
	thread->start();
}

void GUI::paintEvent(QPaintEvent *event)
{
	QString xCoord, yCoord;
	xCoord = ui.XCoordinateText->toPlainText();
	yCoord = ui.YCoordinateText->toPlainText();
	QPainter painter;
	if(Field != NULL)
	{
		painter.begin(this);
		for (int x = 0; x < Field->rozmiar; x++)
		{
			for (int y = 0; y < Field->rozmiar; y++)
			{
				painter.fillRect(110 + (32*x), 10 + (32*y), 32, 32, QColor(0, 0, 0, 255));
			}
		}
	}
	QWidget::paintEvent(event);
	painter.end();
}

void GUI::StartSimulation()
{
	Simulate = true;
}

void GUI::StopSimulation()
{
	Simulate = false;
}

void GUI::Redraw()
{
	this->repaint();
}

void GUI::Step()
{
	/*TODO*/
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

	ui.StepButton->setEnabled(true);
	ui.StartButton->setEnabled(true);
	ui.StopButton->setEnabled(true);
	ui.SaveButton->setEnabled(true);

}