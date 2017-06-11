#pragma once
#include "alghoritms\IAlghoritm.h"
class KruskalAlghoiritm :
	public IAlghoritm
{
public:
	KruskalAlghoiritm();
	~KruskalAlghoiritm();

	void printResult();
	void apply(Graph* graph);
	void setParameters(int, int);
	void prepare(Graph* graph);
};

