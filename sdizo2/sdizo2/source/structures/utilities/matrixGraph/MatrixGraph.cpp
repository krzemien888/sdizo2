#include "stdafx.h"
#include "MatrixGraph.h"


#include "structures\array\Array.h"
#include "structures\list\List.h"

MatrixGraph::MatrixGraph()
{
	m_matrix.resize(0);
}

void MatrixGraph::clear()
{
	m_matrix.resize(0);
	m_amountEdges = 0;
	m_amountPoints = 0;
}

void MatrixGraph::addEdge(const Edge &e)
{
	if (m_matrix.getSize() <= e.getStart().getName() || m_matrix.getSize() <= e.getEnd().getName())
	{
		m_matrix.resize((e.getEnd().getName() > e.getStart().getName()) ? e.getEnd().getName() : e.getStart().getName());
	}

	m_matrix.setValue(e.getStart().getName(), e.getEnd().getName(), e.getValue());
	m_amountEdges++;
	if (!(e.isDirected()))
	{
		m_matrix.setValue(e.getEnd().getName(), e.getStart().getName(), e.getValue());
		m_amountEdges++;
	}
}

void MatrixGraph::addPoint(const Point &p)
{
	m_matrix.resize(m_matrix.getSize() + 1);

	for (int i = 0; i < m_matrix.getSize(); i++)
	{
		m_matrix.setValue(m_matrix.getSize() - 1, i, 0);
		m_matrix.setValue(i, m_matrix.getSize() - 1, 0);
	}
	m_amountPoints++;
}

shared_ptr<Edge> MatrixGraph::getEdge(int a, int b)
{
	if (m_matrix.getValue(a, b) != 0)
		return nullptr;
	else
		return make_shared<Edge>(m_matrix.getValue(a, b), a, b);
}

List<Edge> MatrixGraph::getNeighbours(int p)
{
	List<Edge> output;
	for (int i = 0; i < this->getAmountPoints(); i++)
		if (m_matrix.getValue(p, i) != 0)
			output.pushBack(Edge(m_matrix.getValue(p, i), p, i, true));

	return output;
}


void MatrixGraph::print()
{
	m_matrix.print();
}

void MatrixGraph::resize(int newSize)
{
	m_matrix.resize(newSize);
	m_amountPoints = newSize;
}


MatrixGraph::~MatrixGraph()
{
	clear();
}
