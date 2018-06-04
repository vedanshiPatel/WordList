/*
	Assignment 1

	Name: Vedanshi Patel
	ID: 40068754
	COMP5421
	Date: May 28th 2018
	
*/

// WordlistDriver.cpp

#include "WordList.h"
#include <iostream>
using namespace std;

int main()
{
	const char * filename = "Input.txt"; 

	// build a wordList from an input file.
	WordList wl = WordList(filename); 

	// prints the WordList
	wl.printWordList();

	system("pause");
	return 0;
}