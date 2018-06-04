#include "NumList.h"

// default constructor
NumList::NumList()
{
	size = 0;
	capacity = 10; // initial capacity
	store = new int[capacity];
}

// constructor 
NumList::NumList(int lineNum)
{
	size = 1;
	capacity = 10; // initial capacity
	store = new int[capacity];
	store[0] = lineNum;
}

// destructor
NumList::~NumList()
{
	delete[] store;
}

// copy constructor
NumList::NumList(const NumList& src)
{
	store = NULL;
	*this = src;
}

// copy assign operator
NumList &NumList::operator=(const NumList& src)
{
	delete[] store;
	size = 0;
	capacity = src.capacity;
	store = new int[capacity];

	for (int i = 0; i<src.getSize(); i++)
	{
		addLineNum(src.store[i]);
	}

	return *this;
}

// To check if NumList is empty or not
bool NumList::isEmpty()
{
	return (getSize() == 0);
}

// To check input line number already exists in the array
bool NumList::ifLineNumberPresent(int lineNum)
{
	for (int i = 0; i<getSize(); i++)
	{
		if (store[i] == lineNum) {
			return true;
		}
	}
	return false;
}

// To check if NumList is full
bool NumList::isFull()
{
	return (getSize() >= capacity);
}

// When NumList dynamic array is full, it will be resize
void NumList::resizeArray()
{
	int newCapacity = getCapacity() * 2;
	int *temp = new int[newCapacity];

	for (int i = 0; i < getSize(); i++)
	{
		temp[i] = store[i];
	}

	setCapacity(newCapacity);
	delete[] store;
	store = temp;
	delete[] temp;
}

// To add given line number to current list
void NumList::addLineNum(int lineNum)
{
	if (ifLineNumberPresent(lineNum) == false)
	{
		if (isFull() == false) {
			store[getSize()] = lineNum;
		}
		else {
			resizeArray();
			store[getSize()] = lineNum;
		}

		size++;
	}
}

// To get element at a specified position
int NumList::getElementAtIndext(int index) const
{
	return store[index];
}

// To set specified element at specified index
void NumList::setElementAtIndex(int index, int value)
{
	store[index] = value;
}

// To get size of the numlist
int NumList::getSize() const
{
	return size;
}

// To get capacity of the numlist
int NumList::getCapacity() const
{
	return capacity;
}

// To set capacity to new capacity value
void NumList::setCapacity(int newCapacity)
{
	capacity = newCapacity;
}

// To retrive "store" pointer
const int* NumList::getStoreNumListPointer() const
{
	return store;
}

// To print stored line numbersNumList
void NumList::printLineNums() const
{
	for (int i = 0; i <getSize(); i++)
	{
		cout << store[i];
	}

}

