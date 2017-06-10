#include "stdafx.h"
#include "Graph.h"

void Graph::generate(int density, int points)
{
	for (int i = 0; i < points; i++)
		addPoint(Point(i));

	for (int i = 0; i < getDensity(); i++)
		addEdge(Edge(rand() % 100, getRandomPoint(), getRandomPoint()));

}

List<Edge> Graph::getEdges()
{
	List<Edge> output;

	for (int i = 0; i < getAmountPoints(); i++)
	{
		List<Edge> neighbours = getNeighbours(i);
		while (neighbours.getSize() != 0)
			output.pushBack(neighbours.popFrontElement());
	}
	return output;
}

int Graph::getAmountPoints()
{
	return m_amountPoints;
}

int Graph::getDensity()
{
	return (int)(((float)m_amountEdges)/((float)m_amountPoints));
}

int Graph::getAmountEdges()
{
	return m_amountEdges;
}

Point Graph::getRandomPoint()
{
	return Point(rand() % this->getAmountPoints());
}
