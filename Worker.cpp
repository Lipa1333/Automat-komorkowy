#include "Worker.h"
#include <windows.h>

Worker::Worker() 
{
	Simulate = NULL;
	Window = NULL;
}

Worker::Worker(bool * input, int * inputdata, QMainWindow * app)
{
	Simulate = input;
	Window = app;
	data = inputdata;
}

Worker::~Worker()
{

}

void Worker::process()
{
	for (int i = 0; i < 5; i++)
	{
		if(*Simulate) *data += 10;

		emit finished();
		Sleep(uint(500));
	}

}