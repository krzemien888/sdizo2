#pragma once
#include <stdafx.h>
#include "structures\utilities\point\Point.h"
#include "structures\utilities\edge\Edge.h"

class Graph
{
public:
	Graph() = default;

	virtual void addPoint(Point p) = 0;
	virtual void addEdge(Edge e) = 0;
	virtual void clear() = 0;

	virtual void print() = 0;
	
	virtual ~Graph() = default;
};

