#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef WordData_H
#define WordData_H
#include "NumList.h"
#include <iostream>
#include <string>
using namespace std;


class WordData
{
private:
	char *word;
	int frequency;
	int wordLength;
	NumList numList;

public:
	WordData(string inputword, int lineNum);
	WordData(WordData & src);
	WordData &operator=(WordData & src);
	~WordData();

	//string toLowercase(string word);
	bool checkIfLineNumPresent(int lineNum);
	void addLineNumToList(int lineNum);
	int getFrequency() const;
	int getWordLength() const;
	NumList getNumList() const;
	const char* getWordPointer() const;
	const int* getNumListPointer() const;
	int compareWords(char *inputword);
	const void printWordData() const;
};

#endif

