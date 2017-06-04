#include "stdafx.h"
#include "listGraph.h"

using namespace std;

listGraph::listGraph()
{

}

void listGraph::clear()
{
	m_size = 0;
}

void listGraph::addEdge(const Edge &e)
{

}

void listGraph::addPoint(const Point &p)
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

int listGraph::getSize()
{
	return m_size;
}

void listGraph::print()
{
	for (int i = 0; i < getSize(); i++)
	{
		auto currNode = &(m_data[i]);
		while (currNode != nullptr)
		{
			cout << currNode->data->getStart()->getName() << " ";
			currNode = currNode->next;
		}
		cout << endl;
	}
}

listGraph::~listGraph()
{
	for (int i = 0; i < getSize(); i++)
		m_data[i].clearList();
	delete[] m_data;
}