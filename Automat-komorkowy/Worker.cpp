#include "Worker.h"
#include "GUI.h"
#include <windows.h>

Worker::Worker() 
{
	Simulate = NULL;
	Step = NULL;
	Window = NULL;
}

Worker::Worker(bool * input, bool * step,bool * ready, GUI * app)
{
	Simulate = input;
	Step = step;
	Ready = ready;
	Window = app;
}

Worker::~Worker()
{

}

void Worker::process()
{
	while (1)
	{
		while (*Simulate)
		{
			if (*Ready)
			{
				Field->wykonajTure(Window);
				emit finished();
				*Ready = false;
			}
		}
		if (*Step)
		{
			Field->wykonajTure(Window);
			*Step = false;
			emit finished();
		}
	}
}



/*

*/
