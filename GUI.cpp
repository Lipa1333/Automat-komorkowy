#include "GUI.h"
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
	//connect(ui.StartButton, SIGNAL(released()), this, SLOT(StartSimulation()));
	connect(ui.StopButton, SIGNAL(released()), this, SLOT(StartSimulation()));
	connect(ui.StepButton, SIGNAL(released()), this, SLOT(Step()));
	connect(ui.SaveButton, SIGNAL(released()), this, SLOT(Save()));
	connect(ui.LoadButton, SIGNAL(released()), this, SLOT(Load()));
	thread = new QThread();
	worker = new Worker(&Simulate, &data, this);
	worker->moveToThread(thread);
	connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
	connect(ui.StartButton, SIGNAL(released()), worker, SLOT(process()));
	/*Do not remove for now*/
	//connect(thread, SIGNAL(started()), worker, SLOT(process()));
	//connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
	//connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
	//connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	connect(worker, SIGNAL(finished()), this, SLOT(Redraw()));
	thread->start();
}

void GUI::paintEvent(QPaintEvent *event)
{
	QString xCoord, yCoord;
	xCoord = ui.XCoordinateText->toPlainText();
	yCoord = ui.YCoordinateText->toPlainText();

	QPainter painter;
	painter.begin(this);
	painter.fillRect(110 + data, 10,100,100, Qt::black);
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