#pragma once
#include <QtWidgets/QMainWindow>
#include "Pole.h"

class Worker : public QObject {
	Q_OBJECT
public:
	Worker();
	Worker(bool * input, bool * step, bool * ready, QMainWindow * app);
	~Worker();
	bool * Simulate;
	bool * Step;
	bool * Ready;
	QMainWindow * Window;
	Pole * Field;

public slots:
	void process();

signals:
	void finished();
	void error(QString err);
private:
	// add your variables here
};