#include "Worker.h"
#include <windows.h>

Worker::Worker() 
{
	Simulate = NULL;
	Window = NULL;
}

Worker::Worker(bool * input, QMainWindow * app)
{
	Simulate = input;
	Window = app;
}

Worker::~Worker()
{

}

void Worker::process()
{

		emit finished();

}