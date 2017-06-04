#include "stdafx.h"
#include "Edge.h"
#include "structures/utilities/point/Point.h"


Edge::~Edge()
{
	if(m_startPoint != nullptr)
		delete m_startPoint;
	if(m_endPoint != nullptr)
		delete m_endPoint;
}

Edge::Edge(int value, Point a, Point b)
	: m_value(value)
{
	m_startPoint = new Point(a);
	m_endPoint = new Point(b);
};

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

void Edge::setStart(const Point & a)
{
	if (m_startPoint != nullptr)
		throw new std::invalid_argument("Punkt poczatkowy ju¿ ustawiono");
	else
	{
		m_startPoint = new Point(a);
	}
}

void Edge::setEnd(const Point & b)
{
	if (m_endPoint != nullptr)
		throw new std::invalid_argument("Punkt poczatkowy ju¿ ustawiono");
	else
	{
		m_endPoint= new Point(b);
	}
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
	
	if (m_startPoint != nullptr)
		delete m_startPoint;

	if (m_endPoint != nullptr)
		delete m_endPoint;

	m_startPoint = new Point(*(e.getStart()));
	m_endPoint = new Point(*(e.getEnd()));
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
	return Edge(getValue(), *m_endPoint, *m_startPoint);
}

std::ostream& operator<<(std::ostream& str, const Edge& s) {
	Point* start = s.getStart();
	Point* end = s.getEnd();
	str << start->getName() << " -> " << end->getName() << " (" << s.getValue() << ")";
	return str;
}