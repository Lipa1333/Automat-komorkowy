#pragma once
#include <QtWidgets/QMainWindow>
#include "GUI.h"
#include "Pole.h"

class Worker : public QObject {
	Q_OBJECT
public:
	Worker();
	Worker(bool * input, bool * step, bool * ready, class GUI * app);
	~Worker();
	bool * Simulate;
	bool * Step;
	bool * Ready;
	GUI * Window;
	Pole * Field;

public slots:
	void process();

signals:
	void finished();
	void error(QString err);
private:
	// add your variables here
};