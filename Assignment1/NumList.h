#pragma once
#ifndef NumList_H
#define NumList_H
#include <iostream>
using namespace std;

class NumList
{
private:
	int size;
	int *store;
	int capacity;

public:
	NumList();
	NumList(int lineNum);
	NumList(const NumList& src);
	NumList &operator=(const NumList& src);
	~NumList();

	bool isEmpty();
	bool isFull();
	bool ifLineNumberPresent(int elementToCheck);
	void addLineNum(int lineNum);
	int getSize() const;
	int getCapacity() const;
	void setCapacity(int newCapacity);
	void resizeArray();
	const int* getStoreNumListPointer() const;
	int getElementAtIndext(int index) const;
	void setElementAtIndex(int index, int value);
	void printLineNums() const;
};

#endif

