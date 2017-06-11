#pragma once
#include <stdafx.h>
#include "structures\utilities\point\Point.h"
#include "structures\utilities\edge\Edge.h"
#include "structures\list\List.h"

class Graph
{
public:
	Graph() = default;

	virtual void addPoint(const Point &p) = 0;
	virtual void addEdge(const Edge &e) = 0;
	virtual void generate(int density, int points);
	virtual shared_ptr<Edge> getEdge(int a, int b) = 0;
	virtual List<Edge> getNeighbours(int a) = 0;
	virtual List<Edge> getEdges() = 0;

	virtual void clear() = 0;

	virtual void print() = 0;
	virtual int getAmountPoints();
	virtual int getDensity();
	virtual int getAmountEdges();


	virtual void resize(int newSize) = 0;
	virtual ~Graph() = default;

protected:
	int m_amountPoints = 0;
	int m_amountEdges = 0;
	bool isDirected = true;
	Point getRandomPoint();
};

