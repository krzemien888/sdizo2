#pragma once
#include "stdafx.h"

template<class T>
class Lists
{
public:
	virtual ~List() {};

	virtual void printData();
	
	virtual void pushBack(T value);
	virtual void pushFront(T value);
	virtual void addElement(int index, T value);
	virtual void addElement(T value);
	virtual void removeElement(T value);
	virtual void clearStructure();
	virtual bool findValue(T toFind);

	virtual int getSize();

private:
	class Node {
	public:
		Node(T value) : data(value) {};
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
		T	data;
	};

	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
	bool isEmpty();
	std::shared_ptr<Node> getNodePtr(int index);
	int size = 0;
};



template<class T>
void List<T>::printData()
{
	if (!isEmpty())
	{
		Node* tmp = head.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->next.get();
		}
		cout << endl;

		tmp = tail.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->prev.get();
		}
		cout << endl;
	}
	else
		cout << "Lista jest pusta" << endl;
}

template<class T>
void List<T>::pushBack(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);

	if (!isEmpty())
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else
	{
		tail = newNode;
		head = newNode;
	}

	++size;
}

template<class T>
void List<T>::pushFront(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);

	if (!isEmpty())
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		tail = newNode;
		head = newNode;
	}

	++size;
}

template<class T>
void List<T>::addElement(int index, int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);
	shared_ptr<Node> currNode = getNodePtr(index);

	if (index == 0)
	{
		pushFront(value);
		return;
	}

	if (index == size)
	{
		pushBack(value);
		return;
	}

	if (currNode != nullptr)
	{
		if (currNode->prev == nullptr)
			head = newNode;
		else
			currNode->prev->next = newNode;
		if (currNode->next == nullptr)
			tail = currNode;
		newNode->prev = currNode->prev;
		currNode->prev = newNode;
		newNode->next = currNode;
		++size;
	}
	else if (size == 0 && index == 0)
	{
		pushFront(value);
	}
	else
		throw invalid_argument("Indeks poza zakresem");

}

template<class T>
void List<T>::addElement(int value)
{
	pushBack(value);
}

template<class T>
void List<T>::removeElement(int value)
{
	if (findValue(value))
		--size;

	shared_ptr<Node> toDelete = head;
	while (toDelete != nullptr)
	{
		if (toDelete->data == value)
			break;
		toDelete = toDelete->next;
	}

	if (toDelete != nullptr)
	{
		if (toDelete->prev == nullptr)
			head = toDelete->next;
		else
			toDelete->prev->next = toDelete->next;

		if (toDelete->next == nullptr)
			tail = toDelete->prev;
		else
			toDelete->next->prev = toDelete->prev;

		toDelete->prev.reset();
		toDelete->next.reset();
	}

}

template<class T>
void List<T>::clearStructure()
{
	if (!isEmpty())
	{
		shared_ptr<Node> currNode = head;
		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
			currNode->prev->next.reset();
			currNode->prev.reset();
		}
		head.reset();
		tail.reset();
		size = 0;
	}
}

template<class T>
bool List<T>::findValue(int toFind)
{
	if (isEmpty())
		return false;

	shared_ptr<Node> currNode = head;
	while (currNode != nullptr)
	{
		if (currNode->data == toFind)
			return true;
		currNode = currNode->next;
	}
	return false;
}

template<class T>
int List<T>::getSize()
{
	return size;
}

template<class T>
bool List<T>::isEmpty()
{
	return size == 0;
}

template<class T>
shared_ptr<List<T>::Node> List<T>::getNodePtr(int index)
{
	if (isEmpty())
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode;
}