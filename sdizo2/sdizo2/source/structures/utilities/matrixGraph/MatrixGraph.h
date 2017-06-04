#pragma once
#include "structures\utilities\graph\Graph.h"
#include "structures\matrix\Matrix.h"

class MatrixGraph :
	public Graph
{
public:
	MatrixGraph();

	void clear();
	void addEdge(Edge e);
	void addPoint(Point p);
	void print();

	virtual ~MatrixGraph();

private:
	Matrix m_matrix;
};

