#pragma once

#include "stdafx.h"


class genericTestController
{
public:
	genericTestController() = default;
	virtual ~genericTestController() = default;

	virtual void runAllTests() = 0;

protected:
	virtual void saveToFile(int testSize, double time);
	virtual void saveToFile(std::string message);
	virtual void saveToFile(std::string algorithm, std::string representation, float density, int vertexCount, double totalTime);

	std::string filename;

private:
	std::ofstream file;
};

