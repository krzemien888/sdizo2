#include "stdafx.h"
#include "DjikstraAlghoritm.h"
#undef max

using namespace std;

DjikstraAlghoritm::DjikstraAlghoritm()
{
	switch (outputSetting)
	{
	case AlghoritmOutputSetting::list:
		m_outputListGraph = make_shared<ListGraph>();
		break;
	case AlghoritmOutputSetting::matrix:
		m_outputMatrixGraph = make_shared<MatrixGraph>();
		break;
	default:
		cout << "Nie wybrano formy wynikowego grafu" << endl;
		break;
	}
	queue = make_shared<PriorityQueue<pointValueStructure>>();

}

void DjikstraAlghoritm::apply(Graph * graph)
{
	queue->clearStructure();
	int* distanceArray = new int[graph->getAmountPoints()];
	int* pathArray = new int[graph->getAmountPoints()];
	

	// Set beginning values
	for (int i = 0; i < graph->getAmountPoints(); i++)
	{
		pointValueStructure pointStructure;
		if (i == startPoint)
			pointStructure.value = 0;

		pointStructure.point = i;
		distanceArray[i] = std::numeric_limits<int>::max();
		pathArray[i] = -1;

		queue->addElement(pointStructure);
	}
	
	pathArray[startPoint] = -1;
	distanceArray[startPoint] = 0 ;

	pointValueStructure currPointStruct;
	while (queue->getSize() != 0)
	{
		currPointStruct = queue->popElement();
				
		List<Edge> neighbours = graph->getNeighbours(currPointStruct.point);

		while (neighbours.getSize() != 0)
		{
			Edge currNeighbour = neighbours.popFrontElement();
			int neighbourIndex = queue->getIndex(pointValueStructure(currNeighbour.getEnd().getName()));

			if (queue->getSize() <= neighbourIndex || neighbourIndex < 0)
				continue;

			auto neighbourStruct = queue->popElement(neighbourIndex);

			if (neighbourStruct.value > currNeighbour.getValue() + currPointStruct.value || neighbourStruct.value == numeric_limits<int>::max())
			{
				neighbourStruct.value = currNeighbour.getValue() + currPointStruct.value;
				pathArray[currNeighbour.getEnd().getName()] = currPointStruct.point;
			}

			queue->addElement(neighbourStruct);
		}
		distanceArray[currPointStruct.point] = currPointStruct.value;
	}

	for (int i = 0; i < graph->getAmountPoints(); i++)
		cout << i << "-" << distanceArray[i] << endl;
	for (int i = 0; i < graph->getAmountPoints(); i++)
		cout << i << "-" << pathArray[i] << endl;
	
	delete[] distanceArray;
	delete[] pathArray;
}

void DjikstraAlghoritm::setParameters(int newStartPoint, int)
{
	startPoint = newStartPoint;
}

void DjikstraAlghoritm::printResult()
{
	switch (outputSetting)
	{
	case AlghoritmOutputSetting::list:
		m_outputListGraph->print();
		break;
	case AlghoritmOutputSetting::matrix:
		m_outputMatrixGraph->print();
		break;
	default:
		cout << "Nie wybrano formy wynikowego grafu" << endl;
		break;
	}
}

bool pointValueStructure::operator==(const pointValueStructure & e)
{
	return point == e.point;
}

bool pointValueStructure::operator<(const pointValueStructure & e)
{
	return value < e.value;
}

bool pointValueStructure::operator<=(const pointValueStructure & e)
{
	return *this < e || *this == e;
}

bool pointValueStructure::operator>(const pointValueStructure & e)
{
	return value > e.value;
}

bool pointValueStructure::operator>=(const pointValueStructure & e)
{
	return *this > e || *this == e;
}

bool pointValueStructure::operator!=(const pointValueStructure & e)
{
	return !((*this) == e);
}

std::ostream & operator<<(std::ostream & str, const pointValueStructure & s)
{
	if (s.value == std::numeric_limits<int>::max())
		str << "->" << s.point << "[infinity]";
	else
		str << "->" << s.point << "[" << s.value << "]";
	return str;
}
