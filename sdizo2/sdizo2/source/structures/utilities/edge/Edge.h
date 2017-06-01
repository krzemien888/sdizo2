#pragma once

#include "structures\utilities\point\Point.h"

class Edge
{
	friend std::ostream& operator<<(std::ostream& str, const Edge& s);

public:
	~Edge() = default;
	Edge::Edge() = default;
	Edge::Edge(int value, Point* a, Point* b);

	int getValue() const;
	Point* getStart() const;
	Point* getEnd() const;

	bool operator==(const Edge& e);
	bool operator<(const Edge& e);
	bool operator<=(const Edge& e);
	bool operator>(const Edge& e);
	bool operator>=(const Edge& e);
	bool operator!=(const Edge& e);

private:
	int m_value;
	Point* m_startPoint;
	Point* m_endPoint;
};
