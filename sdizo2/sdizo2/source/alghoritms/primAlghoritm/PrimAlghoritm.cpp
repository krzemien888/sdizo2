#include "stdafx.h"
#include "PrimAlghoritm.h"

PrimAlghoritm::~PrimAlghoritm()
{

}

void PrimAlghoritm::printResult()
{
	int graphSum = 0;
	auto currCon = m_resultList.getNodePtr(0);

	cout << "Lista krawêdzi: " << endl;
	while (currCon != nullptr)
	{
		graphSum += currCon->data.getValue();
		cout << currCon->data << endl;
		currCon = currCon->next.get();
	}
	cout << "Waga grafu: " << graphSum << endl;
}

void PrimAlghoritm::apply(Graph * graph)
{
	m_resultList.clearStructure();
	PriorityQueue<Edge> queue;
	Array<int> parentArray(graph->getAmountPoints(), -1);
	Array<int> costArray(graph->getAmountPoints(), numeric_limits<int>::max());
	Array<bool> addedArray(graph->getAmountPoints(), false);

	costArray.setValue(0, 0);
	queue.addElement(Edge(0, 0, 0));
	while (queue.getSize() != 0)
	{
		auto current = queue.popElement().getEndName();
		addedArray.setValue(current, true);
		auto neighbours = graph->getNeighbours(current);
		auto it = neighbours.getNodePtr(0);
;		while (it != nullptr)
		{
			auto itVal = it->data;
			int neighbourWeight = itVal.getValue();
			int neighbourVertex = itVal.getEndName();
			if (!addedArray.getValue(neighbourVertex) && costArray.getValue(neighbourVertex) > neighbourWeight)
			{
				parentArray.setValue(neighbourVertex, current);
				costArray.setValue(neighbourVertex, neighbourWeight);
				queue.addElement(itVal);
			}
			it = it->next.get();
		}
	}

	for (int i = 0; i < graph->getAmountPoints(); i++)
	{	
		if (parentArray.getValue(i) != -1)
		{
			this->m_resultList.addElement(*(graph->getEdge(i, parentArray.getValue(i))));
		}
	}
}

//This alghoritm doesn't have additional parameters
void PrimAlghoritm::setParameters(int, int)
{}


void PrimAlghoritm::prepare(Graph * graph)
{
	m_currentGraphSize = graph->getAmountPoints();

	m_resultList.clearStructure();
}

int PrimAlghoritm::whoIntroduced(int a) const
{
	return m_resultList.getValue(a).getStartName();
}
