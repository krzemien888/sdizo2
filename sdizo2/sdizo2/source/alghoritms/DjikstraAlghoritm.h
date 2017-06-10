#pragma once
#include "alghoritms\IAlghoritm.h"
#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\priorityQueue\PriorityQueue.h"

#undef max

struct pointValueStructure
{
public:
	pointValueStructure() = default;
	pointValueStructure(int aPoint) { point = aPoint; };
	int point = 0;
	int value = std::numeric_limits<int>::max();

	bool operator==(const pointValueStructure& e);
	bool operator<(const pointValueStructure& e);
	bool operator<=(const pointValueStructure& e);
	bool operator>(const pointValueStructure& e);
	bool operator>=(const pointValueStructure& e);
	bool operator!=(const pointValueStructure& e);
	friend std::ostream& operator<<(std::ostream& str, const pointValueStructure& s);
};

/**
	add O(logn)
	extract-min O(1)
	contains O(logn)
	decrease(logn)

	So, Djikstra O(nlogn)
*/
class DjikstraAlghoritm :
	public IAlghoritm
{
private:
	int startPoint = 0;
	std::shared_ptr<ListGraph> m_outputListGraph;
	std::shared_ptr<MatrixGraph> m_outputMatrixGraph;
	std::shared_ptr<PriorityQueue<pointValueStructure>> queue;
public:
	DjikstraAlghoritm();

	virtual void apply(Graph* graph);
	void setParameters(int newStartPoint, int = 0);
	virtual void printResult();
};


