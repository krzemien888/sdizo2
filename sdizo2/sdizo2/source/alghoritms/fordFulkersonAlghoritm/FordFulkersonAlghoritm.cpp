#include "stdafx.h"
#include "FordFulkersonAlghoritm.h"
#include "structures\queue\Queue.h"
#include "structures\\stack\Stack.h"
#include "structures\utilities\listGraph\listGraph.h"
#include "structures\utilities\matrixGraph\MatrixGraph.h"

void FordFulkersonAlghoritm::setMode(bool useDfs)
{
	m_useDfs = useDfs;
}

void FordFulkersonAlghoritm::printResult()
{
	if (m_angumentedPaths.getSize() != 0)
	{
		auto it = m_angumentedPaths.getNodePtr(0);
		int max = 0;
		while (it != nullptr)
		{
			it->data.edges.printData();
			max += it->data.flow;
			cout << "Przeplyw przez t� �cie�k�: " << it->data.flow << endl << endl;
			it = it->next.get();
		}

		cout << "Maksymalny przeplyw w tym grafie: " << max << endl;
	}
	else
		cout << "Nie odnaleziono " << endl;
}

void FordFulkersonAlghoritm::apply(Graph * graph)
{
	m_angumentedPaths.clearStructure();
	if (this->m_useDfs)
		applyUsingDfs(graph);
	else
		applyUsingBfs(graph);
}

void FordFulkersonAlghoritm::setParameters(int start, int end)
{
	m_startPoint = start;
	m_endPoint = end;
}

void FordFulkersonAlghoritm::prepare(Graph * graph)
{
}

bool FordFulkersonAlghoritm::searchDFS(Graph * graph, int * introducedArray, AngumentedPath & angumentedPath)
{
	Stack<int> stack;
	bool found = false;
	bool * visited = new bool[graph->getAmountPoints()];
	for (int i = 0; i < graph->getAmountPoints(); i++)
		visited[i] = false;
	visited[m_startPoint] = true;
	introducedArray[m_startPoint] = -1;
	/*cout << "DFS" << endl;
	graph->print();*/
	//DFS Search
	int currPoint = -1;
	stack.add(m_startPoint);
	auto startTime = chrono::high_resolution_clock::now();
	double totalTime = 0;
	
	while (!(stack.isEmpty() || found))
	{
		currPoint = stack.pop();

		auto allNeighbours = graph->getNeighbours(currPoint);
		while (allNeighbours.getSize() != 0)
		{
			auto neighbour = allNeighbours.popFrontElement();
			if (!visited[neighbour.getEndName()])
			{
				stack.add(neighbour.getEndName());
				visited[neighbour.getEndName()] = true;
				introducedArray[neighbour.getEndName()] = neighbour.getStartName();
				if (neighbour.getEndName() == m_endPoint)
				{
					found = true;
					break;
				}
			}
			auto endTime = chrono::high_resolution_clock::now();
			totalTime += (double)std::chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
			if (totalTime > 20000000) {
				graph->print();
				system("pause");
				return false;
			}
		}
	}

	delete[] visited;

	return found;
}

bool FordFulkersonAlghoritm::searchBFS(Graph * graph, int* introducedArray, AngumentedPath &aPath)
{
	Queue <int> queue;
	bool found = false;
	bool * visited = new bool[graph->getAmountPoints()];
	for (int i = 0; i < graph->getAmountPoints(); i++)
		visited[i] = false;
	visited[m_startPoint] = true;
	introducedArray[m_startPoint] = -1;

	//BFS Search
	int currPoint = -1;
	queue.add(m_startPoint);
	while (!(queue.isEmpty() || found))
	{
		currPoint = queue.pop();

		auto allNeighbours = graph->getNeighbours(currPoint);

		while (allNeighbours.getSize() != 0)
		{
			auto neighbour = allNeighbours.popFrontElement();
			if (!visited[neighbour.getEndName()])
			{
				queue.add(neighbour.getEndName());
				visited[neighbour.getEndName()] = true;
				introducedArray[neighbour.getEndName()] = neighbour.getStartName();
				if (neighbour.getEndName() == m_endPoint)
				{
					found = true;
					break;
				}
			}
		}
	}

	delete[] visited;

	return found;
}

void FordFulkersonAlghoritm::applyUsingBfs(Graph * graph)
{
	int* introducedArray = new int[graph->getAmountPoints()];

	Graph* residualGraph;
	if (outputSetting == AlghoritmOutputSetting::list)
		residualGraph = new ListGraph(*(static_cast<ListGraph*>(graph)));
	else
		residualGraph = new MatrixGraph(*(static_cast<MatrixGraph*>(graph)));

	AngumentedPath aPath;
	while (searchBFS(residualGraph, introducedArray, aPath))
	{
		/*cout << "alg" << endl;
		graph->print();*/
		//Build AngumentedPath
		int minFlow = numeric_limits<int>::max();
		int currPoint = m_endPoint;
		while (currPoint != m_startPoint)
		{
			auto currEdge = residualGraph->getEdge(introducedArray[currPoint], currPoint);
			if (currEdge->getValue() < minFlow)
				minFlow = currEdge->getValue();
			aPath.edges.pushFront(*currEdge);
			currPoint = introducedArray[currPoint];
		}
		aPath.flow = minFlow;
		
		currPoint = m_endPoint;
		//Applying found flow to angumented path edges
		while (currPoint != m_startPoint)
		{
			residualGraph->decreaseEdgeValue(introducedArray[currPoint], currPoint, aPath.flow);
			residualGraph->increaseEdgeValue(currPoint, introducedArray[currPoint], aPath.flow);
			currPoint = introducedArray[currPoint];
		}

		m_angumentedPaths.pushBack(aPath);
		aPath.edges.clearStructure();

	}

	delete residualGraph;
	delete[] introducedArray;
	
}

void FordFulkersonAlghoritm::applyUsingDfs(Graph * graph)
{
	int* introducedArray = new int[graph->getAmountPoints()];

	Graph* residualGraph;
	if (outputSetting == AlghoritmOutputSetting::list)
		residualGraph = new ListGraph(*(static_cast<ListGraph*>(graph)));
	else
		residualGraph = new MatrixGraph(*(static_cast<MatrixGraph*>(graph)));

	/*cout << "Entry graph" << endl;
	graph->print();*/
	
	AngumentedPath aPath;
	while (searchDFS(residualGraph, introducedArray, aPath))
	{
		/*cout << "Alg" << endl;
		residualGraph->print();*/
		//Build AngumentedPath
		int minFlow = numeric_limits<int>::max();
		int currPoint = m_endPoint;
		while (currPoint != m_startPoint)
		{
			auto currEdge = residualGraph->getEdge(introducedArray[currPoint], currPoint);
			if (currEdge->getValue() < minFlow)
				minFlow = currEdge->getValue();
			aPath.edges.pushFront(*currEdge);
			currPoint = introducedArray[currPoint];
		}
		aPath.flow = minFlow;
		/*cout << "Min flow: " << minFlow << endl;
		cout << "Angumented path" << endl;
		for (int i = 0; i < aPath.edges.getSize(); i++)
		{
			aPath.edges.printData();
		}*/
		currPoint = m_endPoint;
		//Applying found flow to angumented path edges
		while (currPoint != m_startPoint)
		{
			residualGraph->decreaseEdgeValue(introducedArray[currPoint], currPoint, aPath.flow);
			residualGraph->increaseEdgeValue(currPoint, introducedArray[currPoint], aPath.flow);
			currPoint = introducedArray[currPoint];
		}

		m_angumentedPaths.pushBack(aPath);
		aPath.edges.clearStructure();
		/*cout << "Should be cleared " << endl;
		for (int i = 0; i < aPath.edges.getSize(); i++)
		{
			aPath.edges.printData();
		}
		cout << "After change" << endl;
		residualGraph->print();*/
	}

	delete residualGraph;
	delete[] introducedArray;

}
