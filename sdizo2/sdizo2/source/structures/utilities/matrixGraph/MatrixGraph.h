#pragma once
#include "structures\utilities\graph\Graph.h"
#include "structures\array\Array.h"

class MatrixGraph :
	public Graph
{
public:
	MatrixGraph() = default;

	void clear();
	void addEdge(Edge e);
	void addPoint(Point p);
	void print();

	virtual ~MatrixGraph();

private:
	Array<Array<int>> m_matrix;
};

