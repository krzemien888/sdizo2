#include "stdafx.h"
#include "Tester.h"
#include "structures\utilities\disjoinSet\DisjoinSet.h"
#include "alghoritms\DjikstraAlghoritm\DjikstraAlghoritm.h"
#include "alghoritms\bfAlghoritm\bfAlghoritm.h"
#include "alghoritms\fordFulkersonAlghoritm\FordFulkersonAlghoritm.h"
#include "alghoritms\kruskalAlghoritm\KruskalAlghoiritm.h"
#include "alghoritms\primAlghoritm\PrimAlghoritm.h"

using namespace std;

void Tester::runAllTests()
{
	this->filename = "Tests.csv";
	cout << "Minimal spining tree problem started" << endl;
	mstTests();
	cout << "Minimal spining tree problem ended" << endl;

	cout << "Shortest path problem started" << endl;
	sppTests();
	cout << "Shortest path problem ended" << endl;

	cout << "Maximum flow problem started" << endl;
	flowTests();
	cout << "Maximum flow problem ended" << endl;
}


void Tester::sppTests()
{
	cout << "Testing Djikstra alghoritm" << endl;
	djikstraTest();
	cout << "Testing Bellman-Ford alghoritm" << endl;
	bfTest();
}

void Tester::djikstraTest()
{
	MatrixGraph m;

	DjikstraAlghoritm djAlg;
	int vertexCountIndex = 0;
	
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;
	
	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			
			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				djAlg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				djAlg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Djikstra", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime/100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			
			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				djAlg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				djAlg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Djikstra", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::bfTest()
{
	MatrixGraph m;

	bfAlghoritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Bellman-Ford", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Bellman-Ford", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::mstTests()
{
	cout << "Testing Kruskal alghoritm" << endl;
	kruskalTest();
	cout << "Testing Prim alghoritm" << endl;
	primTest();
}

void Tester::kruskalTest()
{
	MatrixGraph m;

	KruskalAlghoiritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, false);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Kruskal", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, false);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Kruskal", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::primTest()
{
	MatrixGraph m;

	PrimAlghoritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, false);
				Alg.prepare(&m);
				try {
					startTime = chrono::high_resolution_clock::now();
					Alg.apply(&m);
					endTime = chrono::high_resolution_clock::now();
				}
				catch (const logic_error &e)
				{
					m.print();
					std::cout << e.what();
					system("pause");
				}

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Prim", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, false);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Prim", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}



void Tester::flowTests()
{
	int old = this->valueRange;
	this->valueRange = 20;
	cout << "Ford - Fulkerson alghoritm with DFS seach testing" << endl;
	ffDFSTest();
	cout << "Ford - Fulkerson alghoritm with BFS seach testing" << endl;
	ffBFSTest();
	this->valueRange = old;
}

void Tester::ffDFSTest()
{
	MatrixGraph m;
	
	FordFulkersonAlghoritm Alg;
	Alg.setMode(true);
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;
	
	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Ford-Fulkerson-DFS", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Ford-Fulkerson-DFS", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::ffBFSTest()
{
	MatrixGraph m;

	FordFulkersonAlghoritm Alg;
	Alg.setMode(false);
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	double totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;
			m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
			for (int i = 0; i < 100; i++)
			{
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Ford-Fulkerson-BFS", "Matrix graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;


			l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
			for (int i = 0; i < 100; i++)
			{
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				double currTime = (double)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
				totalTime += currTime;
				cout << "Progress: " << i * 100 / 100 << "(" << currTime << ")" << "\r";
			}
			cout << endl;
			this->saveToFile("Ford-Fulkerson-BFS", "List graph", densityTable[densityIndex], vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
	
}
