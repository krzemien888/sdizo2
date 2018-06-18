#pragma once
#include "controllers\testControllers\genericTestController\genericTestController.h"
#include "structures\utilities\ListGraph\ListGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"

class Tester :
	public genericTestController
{
public:
	Tester() = default;
	~Tester() = default;

	void runAllTests() override;

private:

	static const int densityArraySize = 4;
	static const int vertexArraySize = 5;
	static const int repeatTest = 100;

	int densityTable[densityArraySize] = {25, 50, 75, 99 };
	int vertexCountTable[vertexArraySize] = { 50, 100, 150, 200, 250 };
	/*int vertexCountTable[vertexArraySize] = { 50, 50, 50, 50, 50};*/
	int valueRange = 100;
	int valueBase = 1;

	void sppTests();
	void djikstraTest();
	void bfTest();
	void mstTests();
	void kruskalTest();
	void primTest();
	void flowTests();
	void ffDFSTest();
	void ffBFSTest();
};

