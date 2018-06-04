#define _CRT_SECURE_NO_WARNINGS
#include "WordList.h"
#include "WordData.h"
#include "NumList.h"


struct WordList::WordNode
{
	WordData * wordData;
	WordNode * next;

	// constructor for WordNode
	WordNode(char *word, int lineNum)
	{
		next = NULL;
		wordData = new WordData(string(word), lineNum);
	}

	// constructor for WordNode
	WordNode(char *word, int lineNum, WordNode * nextWordNode)
	{
		next = nextWordNode;
		wordData = new WordData(string(word), lineNum);
	}

	// Copy constructor of WordNode
	WordNode(WordNode & src)
	{
		wordData = new WordData(*src.wordData);
		next = src.next;
	}

	// destructor
	~WordNode()
	{
		//delete next;
	}

	// To retrive pointer to the next WordNode
	WordNode * getNext()
	{
		return next;
	}

	// To get a pointer to wordData
	WordData * getWordData()
	{
		return wordData;
	}

	// To set the next pointer to given WordNode pointer
	void setNext(WordNode * nextWordNode)
	{
		next = nextWordNode;
	}

};


// Constructor of WorkList, loadList method is called to start building a WordList
WordList::WordList(string inputFileName)
{
	size = 0;
	firstNode = NULL;
	lastNode = NULL;
	buildWordList(inputFileName);
}

// destrctor
WordList::~WordList()
{
	delete firstNode;
	delete lastNode;
}

// To get number of WorkNodes in WordList
int  WordList::getSize() const
{
	return size;
}


// Method to create a linked list of WorkNodes
void WordList::buildWordList(string filename)
{
	ifstream file;
	file.open(filename);

	if (!file) // if file doesn't exist or currently used by another program
	{
		cout << "could not open input file: " << filename << endl;
		exit(1); // To exit the system
	}

	cout << "WordList Source File: " << filename << endl;
	cout << "=================================" << "\n" << endl;

	int linenum = 0;
	string line;
	getline(file, line); // Reads the first line

	while (file)
	{
		linenum++;
		istringstream sin(line); // convert the line just read into input stream
		string word;

		while (sin >> word) // extract word
		{
			word.erase(word.find_last_not_of(" \n\r\t") + 1); // to remove whitespace
			removeCharsFromString(word, "()-,!;.\"+1"); // to remove unwanted characters
			transform(word.begin(), word.end(), word.begin(), tolower); // to lowercase

			if (word == "9" || word == "3" || word == "5")
				continue;

			if (getSize() == 0) // When size of the WorkList is zero, then insert the first WordNode
			{
				firstNode = new WordNode(const_cast<char*>(word.c_str()), linenum);
				lastNode = firstNode;
				size++;
			}
			else
			{
				// When size of the WorkList is greater than 1. 
				AddWordNode(const_cast<char*>(word.c_str()), linenum);
			}

		}
		getline(file, line);

	}
	file.close();
}

// To remove unwanted char from the extracted string
void WordList::removeCharsFromString(string &str, const char* charsToRemove) {
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}


// To add WordNode if it isn't already present
// If given word already exists then just add the lineNum. 
void WordList::AddWordNode(char * words, int lineNum)
{
	WordNode * current = findWordNode(words);
	WordNode * previous = firstNode;

	if (current != NULL) // word is already present in the WordList
	{
		// Add line number to numlist if WordNode already present
		current->getWordData()->addLineNumToList(lineNum);
	}
	else if (current == NULL) // If input word doesn't exist in the current list, then create and add a new WordNode
	{
		current = firstNode;
		int comparedStrings;

		while (true) // insert WordNode at correct position
		{
			comparedStrings = current->getWordData()->compareWords(words);
			if (comparedStrings == -1)
			{
				previous = current;
				current = current->getNext();

				// When current reached the lastNode; therefore, new WordNode will be intersted at the end
				if (current == NULL)
				{
					lastNode = new WordNode(words, lineNum);
					previous->setNext(lastNode);
					size++; // increasing size after adding a new WordNode
					break;
				}
			}
			else
			{
				if (current == firstNode)
				{
					firstNode = new WordNode(words, lineNum);
					firstNode->setNext(current);
					size++;
					break;
				}
				else if (comparedStrings == 1)
				{
					WordNode * newNode = new WordNode(words, lineNum);
					newNode->setNext(current);
					previous->setNext(newNode);
					size++;
					break;
				}
			}
		}
	}
}

// Find if given word already present in the WordList
// if present then return the pointer to that WordNode, if Not return NULL
WordList::WordNode * WordList::findWordNode(char* words)
{
	WordNode *current = firstNode;

	for (int i = 0; i < size; i++)
	{
		if (current->getWordData()->compareWords(words) == 0)
		{
			return current; // word already present in the WordList
		}
		current = current->getNext();
	}
	return NULL;
}

// To print WordList
void  WordList::printWordList() const
{
	char ch = 'A';
	WordNode * current = firstNode;
	cout << "<" << ch << ">" << endl;
	while (current->getNext() != NULL)
	{
		while (ch == toupper(current->getWordData()->getWordPointer()[0]))
		{
			current->getWordData()->printWordData();
			current = current->getNext();
		}
		cout << "<" << ++ch << ">" << endl;

	}
	while (ch < 'Z')
	{
		if (current->getNext() == NULL && (ch == toupper(current->getWordData()->getWordPointer()[0]))) {
			current->getWordData()->printWordData();
		}
		cout << "<" << ++ch << ">" << endl;
	}
	cout << "\n" << "=================================" << "\n" << endl;
}