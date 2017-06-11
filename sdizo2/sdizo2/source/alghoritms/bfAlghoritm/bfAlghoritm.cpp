#include "stdafx.h"
#include "bfAlghoritm.h"

bfAlghoritm::bfAlghoritm()
{
	m_queue = make_unique<PriorityQueue<queueStructure>>();
}

void bfAlghoritm::prepare(Graph * graph)
{
	m_queue->clearStructure();

	m_primalEdgeList = graph->getEdges();
	m_currentGraphSize = graph->getAmountPoints();

	for (int i = 0; i < m_currentGraphSize; i++)
	{
		if(i == m_startPoint)
			m_queue->addElement(queueStructure(i, -1, 0));
		else
			m_queue->addElement(queueStructure(i));
	}
}

void bfAlghoritm::apply(Graph * graph)
{
}

void bfAlghoritm::setParameters(int newStartPoint, int)
{
	m_startPoint = newStartPoint;
}

void bfAlghoritm::printResult()
{
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
