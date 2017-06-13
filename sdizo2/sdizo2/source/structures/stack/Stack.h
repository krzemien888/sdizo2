#pragma once
#include "stdafx.h"

template<class T>
class Stack
{
	friend std::ostream& operator<<(std::ostream& str, const Stack<T>& s);

public:
	Stack() = default;
	~Stack() { clearStructure(); };

	Stack(const Stack<T> &l);
	bool operator==(const Stack<T>& l);

	Stack<T>& operator=(const Stack<T>&l);

	void add(T value);
	T pop();
	bool isEmpty();

	class Node {
	public:
		Node(const T &value) : data(value) {};
		std::shared_ptr<Node> next = nullptr;
		std::shared_ptr<Node> prev = nullptr;
		const T	data;
	};
	typename Stack<T>::Node* getNodePtr(int index);

private:
	void pushBack(const T value);
	void pushFront(T value);
	void addElement(int index, T value);
	void addElement(T value);
	T popFrontElement();
	void removeElement(T value);
	void clearStructure();
	bool findValue(T toFind);
	T getValue(int index) const;
	T* getIterator(int index);

	int getSize() const;
	void setDiplayInline(bool toset);
	bool isInlineDisplayed();


	std::shared_ptr<Node> head = nullptr;
	std::shared_ptr<Node> tail = nullptr;
	bool isEmpty();
	int size = 0;
	bool displayInline = true;
};

using namespace std;

template<class T>
std::ostream& operator<<(std::ostream& str, const Stack<T>& s)
{
	for (auto i = 0; i < s.getSize(); i++)
	{
		str << s.getValue(i);
		if (s.isDisplayedInline())
			str << ' ';
		else
			str << std::endl;
	}
	return str;
}


template<class T>
bool Stack<T>::operator==(const Stack<T>& l)
{
	if (getSize() != l.getSize())
		return false;

	if (getSize() == 0)
		return true;

	bool compare = true;

	typename Stack<T>::Node* l1 = l.getIterator(0);
	typename Stack<T>::Node* l2 = getIterator(0);

	for (auto i = 0; i < getSize(); i++)
	{
		compare = (l1->data == l2->data);
		l1 = l1->next.get();
		l2 = l2->next.get();
	}

}

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& l)
{
	if (this == &l)
		return *this;
	for (int i = 0; i < l.getSize(); i++)
		pushBack(l.getValue(i));
	return *this;
}

template<class T>
void Stack<T>::add(T value)
{
	this->pushFront(value);
}

template<class T>
T Stack<T>::pop()
{
	return popFrontElement();
}

template<class T>
void Stack<T>::setDiplayInline(bool toSet)
{
	displayInline = toSet;
}

template<class T>
inline bool Stack<T>::isInlineDisplayed()
{
	return displayInline;
}

template<class T>
T* Stack<T>::getIterator(int index)
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
T Stack<T>::getValue(int index) const
{
	if (index == 0)
		return head->data;
	if (index == getSize() - 1)
		return tail->data;

	typename Stack<T>::Node* output = head.get();
	for (auto i = 0; i < index; i++)
		output = output->next.get();
	return output->data;
}

template<class T>
inline Stack<T>::Stack(const Stack<T> &l)
{
	for (int i = 0; i < l.getSize(); i++)
		pushBack(l.getValue(i));
}

template<class T>
void Stack<T>::printData()
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
		cout << "Stacka jest pusta" << endl;
}

template<class T>
void Stack<T>::pushBack(const T value)
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
void Stack<T>::pushFront(T value)
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
void Stack<T>::addElement(int index, T value)
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
void Stack<T>::addElement(T value)
{
	pushBack(value);
}

template<class T>
T Stack<T>::popFrontElement()
{
	T output = getValue(0);
	auto toDelete = head;
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
	--size;

	return output;
}

template<class T>
void Stack<T>::removeElement(T value)
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
void Stack<T>::clearStructure()
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
bool Stack<T>::findValue(T toFind)
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
int Stack<T>::getSize() const
{
	return size;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return size == 0;
}

template<class T>
typename Stack<T>::Node* Stack<T>::getNodePtr(int index)
{
	if (isEmpty())
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode.get();
}