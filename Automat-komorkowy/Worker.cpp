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
				//Field->wykonajTure();
				emit finished();
				*Ready = false;
			}
		}
		if (*Step)
		{
			//Field->wykonajTure();
			*Step = false;
			emit finished();
		}
	}
}



/*
vector<float> ExecuteScript(vector<float> cell, const vector<vector<float>> neighbors)
{
	engine.evaluate(program);
	QScriptValue global = engine.globalObject();
	QScriptValue edit = global.property("edit");
	QScriptValue v1 = qScriptValueFromSequence(&engine, cell);
	QScriptValueList args;
	args.append(qScriptValueFromSequence(&engine, cell));
	for (int i = 0; i < neighbors.size(); i++)
	{
		args.append(qScriptValueFromSequence(&engine, neighbors[i]));
	}
	QScriptValue result = edit.call(QScriptValue(), args);
	if (!result.isArray())
	{
		return cell;
	}
	QScriptValueIterator it(result);
	for (int i = 0; i < cell.size(); i++)
	{
		it.next();
		cell[i] = it.value().toNumber();
	}
	return cell;
}
*/
