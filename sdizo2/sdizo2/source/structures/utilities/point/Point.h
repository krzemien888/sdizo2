#pragma once
#include "stdafx.h"

class Point
{
public:
	Point();
	Point(int name);
	~Point();

	int getName() const;

	static int getCounter();
	static void resetCounter(int base);

	bool operator==(const Point& p) const;
	int m_name;

private:
	static int Point::nameCounter;

};

