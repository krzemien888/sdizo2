#include "stdafx.h"
#include "MatrixGraph.h"


void MatrixGraph::clear()
{
	m_matrix.clearStructure();
}

void MatrixGraph::addEdge(Edge e)
{

}

void MatrixGraph::addPoint(Point p)
{
	Array<int> l;
	m_matrix.pushBack(l);
	

	for (auto i = 0; i < m_matrix.getSize(); i++)
	{
		auto row = &(m_matrix[i]);
		while (m_matrix.getSize() != row->getSize())
			row->pushBack(0);
	}
}

void MatrixGraph::print()
{
	for (auto i = 0; i < m_matrix.getSize(); i++)
	{
		auto row = m_matrix.getValue(i);
		row.printData();
	}
}


MatrixGraph::~MatrixGraph()
{
	clear();
}
