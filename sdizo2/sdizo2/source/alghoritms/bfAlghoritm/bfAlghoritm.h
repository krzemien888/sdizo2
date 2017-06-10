#pragma once
#include "alghoritms\IAlghoritm.h"

#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\priorityQueue\PriorityQueue.h"



class bfAlghoritm :
	public IAlghoritm
{
private:
	struct queueStructure {
		Edge edge;
		int parentPoint = 0;
	};

	int startPoint = 0;
	int currentGraphSize = 0;
	std::shared_ptr<PriorityQueue<queueStructure>> queue;
public:

	void prepare(Graph* graph) override;
	void apply(Graph* graph) override;
	void setParameters(int newStartPoint, int = 0);
	void printResult();
};

