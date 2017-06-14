#include "stdafx.h"
#include "Graph.h"


void Graph::generate(int density, int points)
{
	for (int i = 0; i < points; i++)
		addPoint(Point(i));

	for (int i = 0; i < getDensity(); i++)
		addEdge(Edge(rand() % 100, getRandomPoint(), getRandomPoint()));

}

int Graph::getAmountPoints()
{
	return m_amountPoints;
}

int Graph::getDensity()
{
	int maxEdgeAmount = m_amountPoints*(m_amountPoints - 1);;
	int amountOfEdges = m_amountEdges;
	if (!isDirected)
	{
		maxEdgeAmount /= 2;
		amountOfEdges /= 2;
	}

	return (int)((((float)amountOfEdges)/((float)maxEdgeAmount))*100);
}

int Graph::getAmountEdges()
{
	return m_amountEdges;
}

Point Graph::getRandomPoint()
{
	return Point(rand() % this->getAmountPoints());
}

