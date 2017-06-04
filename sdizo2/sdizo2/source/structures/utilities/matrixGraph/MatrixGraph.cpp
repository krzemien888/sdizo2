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
}

void MatrixGraph::addEdge(Edge e)
{
	m_matrix.setValue(e.getStart()->getName(), e.getEnd()->getName(), e.getValue());
	if(!(e.isDirected()))
		m_matrix.setValue(e.getEnd()->getName(), e.getStart()->getName(), e.getValue());
}

void MatrixGraph::addPoint(Point p)
{
	m_matrix.resize(m_matrix.getSize() + 1);

	for (int i = 0; i < m_matrix.getSize(); i++)
	{
		m_matrix.setValue(m_matrix.getSize() - 1, i, 0);
		m_matrix.setValue(i, m_matrix.getSize() - 1, 0);
	}
}

void MatrixGraph::print()
{
	m_matrix.print();
}


MatrixGraph::~MatrixGraph()
{
	clear();
}
