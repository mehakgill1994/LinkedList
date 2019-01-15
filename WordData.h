#ifndef WORDDATA_H
#define WORDDATA_H

#include "NumList.h"
#include <iostream>

class WordData {
private:
	char *word;
	int freq = 0;
	NumList list;
public:
	WordData();
	WordData(char word[], int lineNum);
	WordData(WordData &data);
	void operator=(WordData &data);
	~WordData();
	int getFreq();
	void incrementFreq();
	const char* getWordPointer();
	NumList& getList();
	int compare(char* word1) const;
	friend std::ostream &operator<<(std::ostream &out, const WordData &data);
};

#endif
