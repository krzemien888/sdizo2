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
	List<int> donePoints;
	donePoints.clearStructure();
	donePoints.addElement(0);

	bool firstIteration = true;

	
	while (donePoints.getSize() != m_currentGraphSize)
	{
		auto con = graph->getConnections(donePoints);
		auto currPoint = con.popElement();
		m_resultList.pushBack(currPoint);
		donePoints.addElement(currPoint.getEndName());
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
