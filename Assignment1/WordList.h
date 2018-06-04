#pragma once
#ifndef WORDLIST_H
#define WORDLIST_H
#include "WordData.h"
#include "NumList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class WordList {

private:

	struct WordNode;

	WordNode * firstNode;
	WordNode * lastNode;
	int size;

public:

	WordList(string fname);
	~WordList();
	void buildWordList(string fname);
	void removeCharsFromString(string &str, const char* charsToRemove);
	int getSize() const;
	void AddWordNode(char * words, int lineNum);
	WordNode * findWordNode(char* words);
	void printWordList() const;

};


#endif

