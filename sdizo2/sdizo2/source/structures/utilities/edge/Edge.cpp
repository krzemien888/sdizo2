#include "stdafx.h"
#include "Edge.h"
#include "structures/utilities/point/Point.h"


Edge::Edge(int value, Point* a, Point* b) 
	: m_value(value),
		m_startPoint(a),
		m_endPoint(b)
{};

int Edge::getValue() const
{
	return m_value;
}

Point* Edge::getStart() const
{
	return m_startPoint;
}

Point * Edge::getEnd() const
{
	return m_endPoint;
}

bool Edge::operator==(const Edge & e)
{
	return (m_startPoint == e.getStart() 
		&& m_endPoint == e.getEnd()
		&& m_value == e.getValue());
}

std::ostream& operator<<(std::ostream& str, const Edge& s) {
	Point* start = s.getStart();
	Point* end = s.getEnd();
	str << start->getName() << " -> " << end->getName() << " (" << s.getValue() << ")";
	return str;
}