#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Configure.h"

class Configure : public QMainWindow
{
	Q_OBJECT

public:
	Configure(QWidget *parent = Q_NULLPTR);
	int Colors[6];

private slots:
	void FinishConfigure();

signals:
	void finish();

private:
	Ui::Configure ui;
};
