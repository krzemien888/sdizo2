#pragma once

#include "structures\utilities\graph\Graph.h"
#include "structures\array\Array.h"
#include "structures\utilities\edge\Edge.h"
#include "structures\utilities\point\Point.h"

class ListGraph
	: public Graph
{
public:
	ListGraph();

	void clear();
	void addEdge(const Edge &e) override;
	void addPoint(const Point &p) override;
	shared_ptr<Edge> getEdge(int a, int b) override;
	List<Edge> getEdges() override;
	List<Edge> getNeighbours(int p) override;
	int getSize();
	void print();
	void resize(int newSize) override;
	virtual ~ListGraph();

	class Node {
		public:
			Edge* data = nullptr;
			Node* next = nullptr;
			Node* prev = nullptr;
			~Node() = default;


			void clearList()
			{
				if (next != nullptr)
				{
					next->clearList();
					delete next;
				}
				if(data != nullptr)
					delete data;
			}

	};

private:


	Node* m_data = nullptr;
	int m_size = 0;
};



