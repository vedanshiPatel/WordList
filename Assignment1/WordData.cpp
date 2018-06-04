#include "WordData.h"
#include <iomanip> 

// constructor
WordData::WordData(string inputword, int lineNum)
{
	wordLength = inputword.length();
	word = new char[wordLength];
	strcpy(word, inputword.c_str());
	frequency = 1;
	numList = NumList(lineNum); // when new word is enter it will also initialize Numlist to store lineNum
}

// copy constructor
WordData::WordData(WordData & src)
{
	word = NULL;
	*this = src;
}

// assign operator
WordData & WordData::operator=(WordData & src)
{
	delete[] word;
	wordLength = src.getWordLength();
	word = new char[wordLength];
	strcpy(word, src.getWordPointer());
	frequency = src.getFrequency();
	numList = src.getNumList();
	return *this;
}

// destructor
WordData::~WordData()
{
	delete[] word;
}

// To check if Line number is preset in the list
bool WordData::checkIfLineNumPresent(int lineNum)
{
	return numList.ifLineNumberPresent(lineNum);
}

// If line number is not present in the list then add it to the list
void WordData::addLineNumToList(int lineNum)
{
	numList.addLineNum(lineNum);
	frequency++;
}

// To get frequency
int WordData::getFrequency() const
{
	return frequency;
}

// To get the length of a word
int WordData::getWordLength() const
{
	return wordLength;
}

// To retrive numlist of this wordData
NumList WordData::getNumList() const
{
	return numList;
}

const char * WordData::getWordPointer() const
{
	return word;
}

const int* WordData::getNumListPointer() const
{
	return numList.getStoreNumListPointer();
}

// Compare stored word with an input word
int WordData::compareWords(char *input)
{
	string stroredWord = string(getWordPointer());
	string inputWord = string(input);

	if ((stroredWord.compare(inputWord)) == 0) // input word is present
		return 0;
	else if ((stroredWord.compare(inputWord)) > 0) // storedword greater than inputword
		return 1;
	else if ((stroredWord.compare(inputWord)) < 0) // storedWord smaller than inputword, compared next node
		return -1;

	return -1;
}

// print: word, frequency, line numbers
const void WordData::printWordData() const
{
	cout << setw(15) << word;
	//for (int i = 0; i < getWordLength(); i++)
	//{
	//	cout << word[i] ;
	//}

	cout << setw(3) << "(" << getFrequency() << ")" << "  ";

	for (int i = 0; i< numList.getSize(); i++)
	{
		cout << numList.getElementAtIndext(i) << " ";
	}
	cout << endl;

}



