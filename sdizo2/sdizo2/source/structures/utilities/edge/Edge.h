#pragma once

#include "structures\utilities\point\Point.h"

class Edge
{
	friend std::ostream& operator<<(std::ostream& str, const Edge& s);

public:
	~Edge();
	Edge::Edge() = default;
	Edge::Edge(int value, Point a, Point b);
	
	int getValue() const;
	Point* getStart() const;
	Point* getEnd() const;
	
	void setStart(const Point &a);
	void setEnd(const Point &b);

	bool operator==(const Edge& e);
	bool operator<(const Edge& e);
	bool operator<=(const Edge& e);
	bool operator>(const Edge& e);
	bool operator>=(const Edge& e);
	bool operator!=(const Edge& e);

	Edge& Edge::operator=(Edge& e);

	void setDirected(bool toSet);
	bool isDirected()const;

	Edge getInverted() const;

private:
	bool m_directed = false;
	int m_value = 0;
	Point* m_startPoint = nullptr;
	Point* m_endPoint = nullptr;
};
