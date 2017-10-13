#pragma once
#include <QtWidgets/QMainWindow>

class Worker : public QObject {
	Q_OBJECT
public:
	Worker();
	Worker(bool * input, int * inputdata, QMainWindow * app);
	~Worker();
	bool * Simulate;
	QMainWindow * Window;
	int * data;

	public slots:
	void process();
signals:
	void finished();
	void error(QString err);
private:
	// add your variables here
};