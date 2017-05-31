#pragma once
#include "stdafx.h"

template <class T>
class Array
{
public:
	Array() :
		isCheap(true)
		, allocatedSize(0)
		, currSize(0)
	{};

	Array(int size) :
		data(std::make_unique<T[]>(size))
	{
		allocatedSize = size;
		isCheap = false;
		currSize = 0;
	};

	~Array() {};


	void printData() {
		if (!isEmpty())
			for (int index = 0; index < this->currSize; index++)
				std::cout << data[index] << ' ';
		else
			std::cout << "Tablica jest pusta!";
		std::cout << std::endl;
	};


	void addElement(int index, T value) {
		if (isEmpty() && index == 0)
		{
			data = std::make_unique<T[]>(1);
			allocatedSize = 1;
			data[index] = value;
			++currSize;
		}
		else if (index >= 0 && index <= currSize)
		{
			if (allocatedSize < currSize + 1)
				if (isCheap)
					this->realocate(allocatedSize + 1);
				else
					realocateByStep();
			moveElementsRight(index);
			data[index] = value;
			++currSize;
		}
		//else if (index == currSize)
		//	pushBack(value);
		else
		{
			throw std::invalid_argument("Indeks poza zasiêgiem tablicy");
		}
	};


	void pushBack(T value) {
		addElement(getSize(), value);
	/*	if (allocatedSize < currSize + 1)
			if (isCheap)
				this->realocate(allocatedSize + 1);
			else
				realocateByStep();
		currSize++;
		data[currSize - 1] = value;*/
	};


	void removeElement(int index) {
		if (index >= 0 && index < getSize())
		{
			moveElementsLeft(index);
			if(isCheap)
				realocate(allocatedSize - 1);
		}
		else
		{
			std::stringstream ss;
			ss << "Indeks poza zasiêgiem tablicy( podano: " << index << " max: " << getSize();
			throw std::invalid_argument(ss.str());
		}
	};


	void clearStructure() {
		data.reset();
		currSize = 0;
		allocatedSize = 0;
	};


	void realocate(int newSize) {
		if (newSize == 0)
		{
			data.reset();
			currSize = 0;
			allocatedSize = 0;
		}

		std::unique_ptr<T[]> newData = std::make_unique<T[]>(newSize);
		int moveDataToIndex = (newSize > currSize) ? currSize : newSize;
		for (int index = 0; index < moveDataToIndex; index++)
			newData[index] = data[index];
		data.reset();
		data = std::move(newData);
		allocatedSize = newSize;
		currSize = moveDataToIndex;
	};


	bool findValue(T toFind) {
		for (int index = 0; index < currSize; index++)
			if (data[index] == toFind)
				return true;
		return false;
	};
	int getSize() {
		return currSize;
	};

	bool isEmpty() {
		return (currSize == 0);
	};

	T getValue(int index) {
		if (index >= currSize)
			throw std::invalid_argument("Out of Array range");
		return data[index];
	};
	void setValue(int index, T value) {
		if (index >= currSize)
			throw std::invalid_argument("Out of Array range");
		data[index] = value;
	};
	void swap(int b, int a) {
		T tmp = data[b];
		data[b] = data[a];
		data[a] = tmp;
	};
	T operator[](int index) {
		return data[index];
	};

	int getAllocatedSize() const
	{
		return allocatedSize;
	};

private:
	std::unique_ptr<T[]> data;
	int currSize = 0;
	int allocatedSize = 0;
	int realocationStep = 1;

	void moveElementsRight(int index) {
		for (int i = allocatedSize - 1; i > index; --i)
			data[i] = data[i - 1];
	};
	void moveElementsLeft(int index) {
		for (int i = index; i < currSize - 1; ++i)
			data[i] = data[i + 1];
	};

	bool isCheap;
protected:
	void realocateByStep() {
		realocate(allocatedSize * 2);
	};
};
