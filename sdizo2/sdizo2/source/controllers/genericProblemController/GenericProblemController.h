#pragma once
#include "source\controllers\genericController\GenericController.h"
#include "structures\utilities\ListGraph\ListGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"


class GenericProblemController :
	public GenericController
{
private:
	MatrixGraph m_matrix;
	ListGraph m_list;

public:
	GenericProblemController() = default;
	virtual ~GenericProblemController() = default;

	virtual void loadFromFile();
	virtual void handleAdditionalParameters(std::string) = 0;
	virtual void parseEdgeString(std::string);
	virtual void print();
};

