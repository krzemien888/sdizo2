#include "stdafx.h"
#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph()
{

}

void ListGraph::clear()
{
	for (int i = 0; i < getSize(); i++)
		m_data[i].clearList();
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	m_amountEdges = 0;
	m_amountPoints = 0;
}

void ListGraph::addEdge(const Edge &e)
{
	Node* lastNode = &(m_data[e.getStart().getName()]);

	while (lastNode->next != nullptr)
		lastNode = lastNode->next;
	
	lastNode->next = new Node();
	lastNode->next->data = new Edge(e);
	lastNode->next->prev = lastNode;
	if (!e.isDirected())
	{
		Edge newE = e.getInverted();
		newE.setDirected(true);
		addEdge(newE);
	}
	m_amountEdges++;
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
	m_amountPoints++;
}

shared_ptr<Edge> ListGraph::getEdge(int a, int b)
{
	if (a >= m_size || a < 0)
		throw new out_of_range("Podany punkt jest poza zasiêgiem tablicy");
	
	Node* curr = m_data[a].next;
	
	while (curr != nullptr)
	{
		if (curr->data->getEnd().getName() == b)
			return make_shared<Edge>(*(curr->data));
		else
			curr = curr->next;
	}
	return nullptr;
}

List<Edge> ListGraph::getNeighbours(int p)
{
	List<Edge> output;
	Node* curr = (m_data[p]).next;

	while (curr != nullptr)
	{
		output.pushBack(*(curr->data));
		curr = curr->next;
	}
	return output;
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
			if (currNode == &(m_data[i]))
			{
				cout << currNode->data->getStart().getName() << " ";
				cout << " | ";
			}
			else
				cout << currNode->data->getEnd().getName() << " ";
			currNode = currNode->next;
		}
		cout << endl;
	}
}

void ListGraph::resize(int newSize)
{
	for (int i = getSize(); i < newSize; i++)
		addPoint(i);
}

ListGraph::~ListGraph()
{
	clear();
}