#pragma once
#include "structures\utilities\graph\Graph.h"
#include "structures\list\List.h"

class MatrixGraph :
	public Graph
{
public:
	MatrixGraph();



	virtual ~MatrixGraph();

private:
	List<List<int>> m_matrix;
};

