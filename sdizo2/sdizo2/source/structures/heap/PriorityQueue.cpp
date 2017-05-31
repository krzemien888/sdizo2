#include "stdafx.h"
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue()
{
	array = make_unique<Array<Edge>>(20);
}

PriorityQueue::PriorityQueue(int size)
{
	array = make_unique<Array<Edge>>(size * 2);
}

void PriorityQueue::addElement(Edge &elem)
{
	array->pushBack(elem);
	fixUp();
	++m_size;
}

void PriorityQueue::clearStructure()
{
	array->clearStructure();
	m_size = 0;
}


bool PriorityQueue::findValue(Edge &value)
{
	if (array->isEmpty())
		return false;

	return array->findValue(value);
}


Edge PriorityQueue::popElement()
{
	if (m_size != 0)
	{
		Edge output = array->getValue(0);
		array->swap(0, array->getSize() - 1);
		array->removeElement(array->getSize() - 1);
		fixDown(0);
		--m_size;
		return output;
	}
	else
		throw new logic_error("Queue is empty!");
}

int PriorityQueue::getSize()
{
	return m_size;
}


void PriorityQueue::printData()
{
	printNode(string(""), string(""), 0);
}

void PriorityQueue::fixUp()
{
	if (array->getSize() < 1)
		return;
	int currNode = array->getSize() - 1;
	int parentNode = (currNode - ((currNode % 2 == 0)? 2:1)) / 2;
	while (currNode != 0)
	{
		if (array->getValue(parentNode).getValue() < array->getValue(currNode).getValue())
			array->swap(parentNode, currNode);
		currNode = parentNode;
		parentNode = (currNode - ((currNode % 2 == 0) ? 2 : 1)) / 2;
	}
}

void PriorityQueue::fixDown(int index)
{
	int leftChild;
	int rightChild;
	int parent;
	bool isLeft, isRight, shifted;
	isLeft = isRight = shifted = true;

	while ((isLeft || isRight) && shifted)
	{
		isLeft = isRight = true;
		shifted = false;
		leftChild = index * 2 + 1;
		rightChild = index * 2 + 2;

		isLeft = (leftChild < array->getSize());
		isRight = (rightChild < array->getSize());
		parent = (int)(index - 1) / 2;

		if (parent >= 0)
			if (array->getValue(parent).getValue() < array->getValue(index).getValue())
			{
				fixDown(parent);
				return;
			}

		if (isRight && isLeft)
		{
			if ((array->getValue(rightChild)).getValue() > array->getValue(leftChild).getValue())
			{
				if (array->getValue(rightChild).getValue() > array->getValue(index).getValue())
				{
					array->swap(index, rightChild);
					index = rightChild;
					shifted = true;
				}
			}
			else
			{
				if (array->getValue(leftChild).getValue() > array->getValue(index).getValue())
				{
					array->swap(index, leftChild);
					index = leftChild;
					shifted = true;
				}
			}
		}
		else if (isRight)
		{
			if (array->getValue(rightChild).getValue() > array->getValue(index).getValue())
			{
				array->swap(index, rightChild);
				index = rightChild;
				shifted = true;
			}
		}
		else if (isLeft)
		{
			if (array->getValue(leftChild).getValue() > array->getValue(index).getValue())
			{
				array->swap(index, leftChild);
				index = leftChild;
				shifted = true;
			}
		}
	}
}

void PriorityQueue::printNode(string& sMiddle, string &sBefore, int currNode)
{
	string s;
	if (currNode < array->getSize())
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << array->getValue(currNode) << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), 2 * currNode + 1);
	}
}
