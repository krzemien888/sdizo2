#include "stdafx.h"
#include "bfAlghoritm.h"

using namespace std;

bfAlghoritm::~bfAlghoritm()
{
	if (m_array != nullptr)
		delete[] m_array;
}

void bfAlghoritm::prepare(Graph * graph)
{
	m_currentGraphSize = graph->getAmountPoints();

	delete[] m_array;
	m_array = nullptr;
	
	m_array = new queueStructure[m_currentGraphSize];

	m_primalEdgeList = graph->getEdges();

	for (int i = 0; i < m_currentGraphSize; i++)
	{
		if(i == m_startPoint)
			m_array[i] = queueStructure(i, -1, 0);
		else
			m_array[i] = queueStructure(i);
	}
}

void bfAlghoritm::apply(Graph * graph)
{
	for (int i = 0; i < m_currentGraphSize - 1; i++)
	{
		bool corrected = false;
		auto listIterator = m_primalEdgeList.getNodePtr(0);
		for (int i = 0; i < m_primalEdgeList.getSize(); i++)
		{
			Edge currEdge = listIterator->data;
			
			if (m_array[currEdge.getStartName()].value == numeric_limits<int>::max() )
			{
				listIterator = listIterator->next.get();
				continue;
			}
			
			if(m_array[currEdge.getEndName()].value > m_array[currEdge.getStartName()].value + currEdge.getValue())
			{
				m_array[currEdge.getEndName()].value = m_array[currEdge.getStartName()].value + currEdge.getValue();
				m_array[currEdge.getEndName()].parentPoint = currEdge.getStartName();
				corrected = true;
			}

			listIterator = listIterator->next.get();
		}
		if (!corrected)
		{
			break;
		}
	}
}

void bfAlghoritm::setParameters(int newStartPoint, int)
{
	m_startPoint = newStartPoint;
}

void bfAlghoritm::printResult()
{
	List<int> displayer;

	cout << "Punkt startowy: " << m_startPoint << endl;
	cout << "Cel\tDystans\tTor" << endl;
	for (int i = 0; i < m_currentGraphSize; i++)
	{
		cout << i << "\t" << m_array[i].value << "\t";
		auto pathFinder = i;
		while (pathFinder != -1)
		{
			displayer.pushFront(pathFinder);
			pathFinder = m_array[pathFinder].parentPoint;
		}
		while (displayer.getSize() != 0)
			cout << displayer.popFrontElement() << " ";
		cout << endl;
	}
}

bfAlghoritm::queueStructure::queueStructure(int apoint)
{
	point = apoint;
}

bfAlghoritm::queueStructure::queueStructure(int apoint, int aparentPoint, int avalue)
{
	point = apoint;
	parentPoint = aparentPoint;
	value = avalue;
}

bool bfAlghoritm::queueStructure::operator==(const queueStructure & e)
{
	return point == e.point;
}

bool bfAlghoritm::queueStructure::operator<(const queueStructure & e)
{
	return value < e.value;
}

bool bfAlghoritm::queueStructure::operator<=(const queueStructure & e)
{
	return value <= e.value;
}

bool bfAlghoritm::queueStructure::operator>(const queueStructure & e)
{
	return value > e.value;
}

bool bfAlghoritm::queueStructure::operator>=(const queueStructure & e)
{
	return value >= e.value;
}

bool bfAlghoritm::queueStructure::operator!=(const queueStructure & e)
{
	return !(*this == e);
}

std::ostream & operator<<(std::ostream & str, const bfAlghoritm::queueStructure & s)
{
	str << s.point << " - ";
	if (s.value == std::numeric_limits<int>::max())
		str << "infinity";
	else
		str << s.value;
	str << " parent " << s.parentPoint;
	return str;
}
