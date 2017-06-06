#include "stdafx.h"
#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph()
{

}

void ListGraph::clear()
{
	m_size = 0;
}

void ListGraph::addEdge(const Edge &e)
{
	Node* lastNode = &(m_data[e.getStart()->getName()]);

	while (lastNode->next != nullptr)
		lastNode = lastNode->next;
	
	lastNode->next = new Node();
	lastNode->next->data = new Edge();
	lastNode->next->data->setStart(*e.getStart());
	lastNode->next->data->setEnd(*e.getEnd());
	lastNode->next->prev = lastNode;
	if (!e.isDirected())
	{
		Edge newE = e.getInverted();
		newE.setDirected(true);
		addEdge(newE);
	}
}

void ListGraph::addPoint(const Point &p)
{
	if (m_data == nullptr)
	{
		m_data = new Node[1];
	}
	else
	{
		int newSize = getSize() + 1;
		Node* newData = new Node[newSize];
		for (int i = 0; i < getSize(); i++)
		{
			newData[i] = m_data[i];
			Node* tmp = m_data[i].next;
			while (tmp != nullptr)
			{
				newData[i].next = tmp;
				tmp = tmp->next;
			}
		}

		delete[] m_data;
		m_data = newData;

	}
	m_size++;
	m_data[getSize() - 1].data = new Edge;
	m_data[getSize() - 1].data->setStart(p);
}

int ListGraph::getSize()
{
	return m_size;
}

void ListGraph::print()
{
	for (int i = 0; i < getSize(); i++)
	{
		auto currNode = &(m_data[i]);
		while (currNode != nullptr)
		{
			if(currNode == &(m_data[i]))
				cout << currNode->data->getStart()->getName() << " ";
			else
				cout << currNode->data->getEnd()->getName() << " ";
			currNode = currNode->next;
		}
		cout << endl;
	}
}

ListGraph::~ListGraph()
{
	for (int i = 0; i < getSize(); i++)
		m_data[i].clearList();
	delete[] m_data;
}