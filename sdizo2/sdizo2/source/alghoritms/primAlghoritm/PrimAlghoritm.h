#pragma once
#include "alghoritms\IAlghoritm.h"
class PrimAlghoritm :
	public IAlghoritm
{
public:
	PrimAlghoritm();
	~PrimAlghoritm();
	void printResult();
	void apply(Graph* graph);
	void setParameters(int, int);
	void prepare(Graph* graph);
};

