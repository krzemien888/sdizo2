#include "stdafx.h"
#include "Edge.h"
#include "structures/utilities/point/Point.h"


Edge::~Edge()
{
}

Edge::Edge(int value, Point a, Point b)
	: m_value(value)
{
	m_startPoint = Point(a);
	m_endPoint = Point(b);
}
Edge::Edge(int value, Point a, Point b, bool isDirected)
	: m_value(value)
{
	m_startPoint = Point(a);
	m_endPoint = Point(b);
	m_directed = isDirected;
}
Edge::Edge(const Edge & e)
{
	m_startPoint = Point(e.getStart());
	m_endPoint = Point(e.getEnd());
	m_value = e.getValue();
}
;

int Edge::getValue() const
{
	return m_value;
}

Point Edge::getStart() const
{
	return m_startPoint;
}

Point Edge::getEnd() const
{
	return m_endPoint;
}

void Edge::setStart(const Point & a)
{
	m_startPoint = Point(a);
}

void Edge::setEnd(const Point & b)
{
	m_endPoint = Point(b);

}

bool Edge::operator==(const Edge & e)
{
	return (m_startPoint == e.getStart() 
		&& m_endPoint == e.getEnd()
		&& m_value == e.getValue());
}

bool Edge::operator<(const Edge & e)
{
	return (getValue() < e.getValue());
}

bool Edge::operator<=(const Edge & e)
{
	return (getValue() < e.getValue() || (*this) == e);
}

bool Edge::operator>(const Edge & e)
{
	return (getValue() > e.getValue());
}

bool Edge::operator>=(const Edge & e)
{
	return (getValue() > e.getValue() || (*this) == e);
}

bool Edge::operator!=(const Edge & e)
{
	return !((*this) == e);
}

Edge & Edge::operator=(Edge & e)
{
	if (this == &e)
		return *this;
	
	m_startPoint = Point(e.getStart());
	m_endPoint = Point(e.getEnd());
	m_value = e.getValue();

	return *this;
}

void Edge::setDirected(bool toSet)
{
	m_directed = toSet;
}

bool Edge::isDirected() const
{
	return m_directed;
}

Edge Edge::getInverted() const
{
	return Edge(getValue(), m_endPoint, m_startPoint);
}

std::ostream& operator<<(std::ostream& str, const Edge& s) {
	Point start = s.getStart();
	Point end = s.getEnd();
	str << start.getName() << " -> " << end.getName() << " (" << s.getValue() << ")";
	return str;
}