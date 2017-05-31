#pragma once
#include "stdafx.h"

#include "structures/array/Array.h"
#include "structures\utilities\edge\Edge.h"

class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(int size);
	virtual ~PriorityQueue() {};

	virtual void addElement(Edge &value);
	virtual void clearStructure();
	virtual bool findValue(Edge &value);
	virtual Edge popElement();
	virtual int getSize();
	virtual void printData();

private:
	virtual void fixUp();
	virtual void fixDown(int index);

	int m_size;
	
protected:
	std::unique_ptr<Array<Edge>> array;
	void printNode(std::string &sMiddle, std::string &sBefore, int currNode);
	
};
