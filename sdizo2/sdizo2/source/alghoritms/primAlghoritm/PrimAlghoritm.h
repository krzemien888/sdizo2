#pragma once
#include "alghoritms\IAlghoritm.h"
#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\priorityQueue\PriorityQueue.h"
#include "alghoritms\DjikstraAlghoritm\DjikstraAlghoritm.h"

class PrimAlghoritm :
	public IAlghoritm
{
public:
	PrimAlghoritm() = default;
	~PrimAlghoritm();
	void printResult() override;
	void apply(Graph* graph) override;
	void setParameters(int, int) override;
	void prepare(Graph* graph) override;

private:
	int m_currentGraphSize = 0;
	List<Edge> m_resultList;

	int whoIntroduced(int) const;
};

