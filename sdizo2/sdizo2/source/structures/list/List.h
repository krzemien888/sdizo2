#pragma once
#include "stdafx.h"

template<class T>
class List
{
	friend std::ostream& operator<<(std::ostream& str, const List<T>& s);

public:
	virtual ~List() { clearStructure(); };

	void printData();
	
	void pushBack(T value);
	void pushFront(T value);
	void addElement(int index, T value);
	void addElement(T value);
	void removeElement(T value);
	void clearStructure();
	bool findValue(T toFind);
	T getValue(int index);
	T* getIterator(int index);
	T* begin();
	T* end();

	virtual int getSize();
	bool operator==(const List<T>& l);

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
	typename List<T>::Node* getNodePtr(int index);
	int size = 0;
};

using namespace std;

template<class T>
std::ostream& operator<<(std::ostream& str, const List<T>& s)
{
	for (auto i = 0; i < m_matrix.getSize(); i++)
		str <<  m_matrix.getValue(i);

	return str;
}

template<class T>
bool List<T>::operator==(const List<T>& l)
{
	if (getSize() != l.getSize())
		return false;

	if (getSize() == 0)
		return true;

	bool compare = true;

	typename List<T>::Node* l1 = l.getIterator(0);
	typename List<T>::Node* l2 = getIterator(0);

	for (auto i = 0; i < getSize(); i++)
	{
		compare = (l1->data == l2->data);
		l1 = l1->next.get();
		l2 = l2->next.get();
	}

}

template<class T>
T* List<T>::getIterator(int index)
{
	if (index == 0)
		return &(head.get()->data);
	if (index == getSize() - 1)
		return &(tail.get()->data);

	auto output = head.get();

	if (!output)
		return nullptr;

	for (auto i = 0; i <= index; i++)
		output = output->next.get();
	return &(output->data);
}

template<class T>
T List<T>::getValue(int index)
{
	if (index == 0)
		return head->data;
	if (index == getSize() - 1)
		return tail->data;

	typename List<T>::Node* output = head.get();
	for (auto i = 0; i <= index; i++)
		output = output->next.get();
	return output->data;
}

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
	}
	else
		cout << "Lista jest pusta" << endl;
}

template<class T>
void List<T>::pushBack(T value)
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
void List<T>::pushFront(T value)
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
void List<T>::addElement(int index, T value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);
	shared_ptr<Node> currNode = make_shared<Node>(getNodePtr(index));

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
void List<T>::addElement(T value)
{
	pushBack(value);
}

template<class T>
void List<T>::removeElement(T value)
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
bool List<T>::findValue(T toFind)
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
typename List<T>::Node* List<T>::getNodePtr(int index)
{
	if (isEmpty())
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode;
}