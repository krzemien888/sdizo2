#pragma once

#include "structures\array\Array.h"
#include "structures\utilities\edge\Edge.h"
#include "structures\utilities\point\Point.h"

class ListGraph
{
public:
	ListGraph();

	void clear();
	void addEdge(const Edge &e);
	void addPoint(const Point &p);
	int getSize();
	void print();

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



