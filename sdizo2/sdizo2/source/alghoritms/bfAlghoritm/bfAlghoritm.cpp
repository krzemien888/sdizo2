#include "stdafx.h"
#include "bfAlghoritm.h"

using namespace std;

//bfAlghoritm::~bfAlghoritm()
//{
//	if (m_array != nullptr)
//		delete[] m_array;
//}

void bfAlghoritm::prepare(Graph * graph)
{
	m_currentGraphSize = graph->getAmountPoints();
	
	m_array.clearStructure();

	//m_primalEdgeList = graph->getEdges();

	for (int i = 0; i < m_currentGraphSize; i++)
	{
		if (i == m_startPoint)
		{
			m_array.addElement(i, queueStructure(i, -1, 0));
		}
		else
		{
			m_array.addElement(i, queueStructure(i, -1, std::numeric_limits<int>::max()));
		}
	}


}

void bfAlghoritm::apply(Graph * graph)
{
	List<Edge> edges = graph->getEdges();
	for (int i = 0; i < m_currentGraphSize - 1; i++)
	{
		bool corrected = false;
		List<Edge>::Node* listIterator = edges.getNodePtr(this->m_startPoint);
		while(listIterator != nullptr)
		{
			int end = listIterator->data.getEndName();
			int start = listIterator->data.getStartName();
			
			if (m_array.getValue(start).value == numeric_limits<int>::max() )
			{
				listIterator = listIterator->next.get();
				continue;
			}
			
			if(m_array.getValue(end).value > m_array.getValue(start).value + listIterator->data.getValue())
			{
				auto startStructurePtr = this->m_array.getPtr(start);
				auto endStructurePtr = this->m_array.getPtr(end);
				endStructurePtr->value = startStructurePtr->value + listIterator->data.getValue();
				endStructurePtr->parentPoint = start;
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
		cout << i << "\t" << m_array.getValue(i).value << "\t";
		auto pathFinder = i;
		while (pathFinder != -1)
		{
			displayer.pushFront(pathFinder);
			pathFinder = m_array.getValue(pathFinder).parentPoint;
		}
		while (displayer.getSize() != 0)
			cout << displayer.popFrontElement() << " ";
		cout << endl;
	}
}

bfAlghoritm::queueStructure::queueStructure()
{
	this->value = std::numeric_limits<int>::max();
}

bfAlghoritm::queueStructure::queueStructure(int apoint)
{
	point = apoint;
	this->value = std::numeric_limits<int>::max();
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
