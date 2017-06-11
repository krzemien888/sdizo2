#pragma once
#include "structures\utilities\graph\Graph.h"
#include "structures\matrix\Matrix.h"

class MatrixGraph :
	public Graph
{
public:
	MatrixGraph();

	void clear();
	void addEdge(const Edge &e) override;
	void addPoint(const Point &p) override;
	shared_ptr<Edge> getEdge(int a, int b) override;
	List<Edge> getEdges() override;
	List<Edge> getNeighbours(int p) override;
	void print();
	void resize(int newSize) override;

	virtual ~MatrixGraph();

private:
	Matrix m_matrix;
};

