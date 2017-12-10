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
	//! Variable pointer to determinate simulation progress
	bool * Simulate;
	//! Variable pointer to determinate simulation progress by one step
	bool * Step;
	//! Variable pointer to determinate simulation progress after redrawing
	bool * Ready;
	class GUI * Window;
	//! Variable pointer to Field on which simulation will be done
	class Pole * Field;

public slots:
	//! Function processing simulation for the field of cells
	void process();

signals:
	void finished();
	void error(QString err);
private:
};