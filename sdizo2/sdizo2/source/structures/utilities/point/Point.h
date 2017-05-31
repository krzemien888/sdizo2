#pragma once
#include "stdafx.h"

class Point
{
public:
	Point() = default;
	Point(std::string name) : m_name(name) {}
	~Point() = default;

	std::string getName();

private:
	std::string m_name;
};

