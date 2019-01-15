#include "WordList.h"
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//default constructor
WordList::WordList() {
	head = nullptr;
	tail = nullptr;
}

WordList::WordList(string filename) {
	head = nullptr;
	tail = nullptr;

	
	ifstream fin(filename);
	if (!fin) {
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	int linenum = 0;
	string line;
	getline(fin, line);
	while (fin) {
		++linenum;
		istringstream sin(line);
		string word;
		while (sin >> word) {
			
			//trimming the word for non-alphabet characters
			bool deleted = false;
			string::iterator it = word.begin(); 
			while(it!=word.end())
			{
				deleted = false;
				if (!((*it <= 'z' && *it >= 'a') || (*it <= 'Z' && *it >= 'A'))) {
					word.erase(it);
					deleted = true;
				}
				
				if (!deleted)
					break;
			}

			if (word.empty()) {
				continue;
			}

			it = word.end() - 1;
			while (it != word.begin())
			{
				deleted = false;
				if (!((*it <= 'z' && *it >= 'a') || (*it <= 'Z' && *it >= 'A'))) {
					word.erase(it);
					deleted = true;
				}

				if (!deleted)
					break;
				else
					it--;
			}
			//end of word trimming
			
			
			char * charArrayWord = new char[word.length() + 1];
			strcpy_s(charArrayWord, word.length()+1, word.c_str());
			
			//adding elements to list in a sorted manner
			WordNode* temp = new WordNode(charArrayWord, linenum);
			WordNode* ptr = head;
			WordNode* prevPtr = nullptr;
			WordData* thisData = ptr->getWordDataPtr();
			bool found = false;
			int result;
			while (ptr != nullptr) {
				
				result = thisData->compare(charArrayWord);
				if (result == -1) {
					prevPtr = ptr;
					ptr = ptr->getNext();
					thisData = ptr->getWordDataPtr();
				}
				else if (result == 0) {
					thisData->getList().add(linenum);
					thisData->incrementFreq();
					found = true;
					break;
				}
				else if (result == 1) {
					temp->setNext(ptr);
					if (prevPtr == nullptr) {
						prevPtr = temp;
						head = prevPtr;
					}
					else
					{
						prevPtr->setNext(temp);
					}
					
					break;
				}
			}
			if (ptr == head && !found) {
				head = temp;
				tail = temp;
			}
			else if (ptr == nullptr && ptr != head){
				prevPtr->setNext(temp);
				tail = temp;
			}
			//
			delete[] charArrayWord;
		}
		getline(fin, line);
	}
	fin.close();
}

//destructor
WordList::~WordList() {
	delete head;
	delete tail;
}

//overloaded ostream operator
std::ostream &operator<<(std::ostream &out, const WordList &list) {
	
	list.print(out);
	return out;
}

//printing entire list in specified format
void WordList::print(std::ostream &out) const {
	WordNode* p = head;
	char c = 'A';
	while (p != nullptr) {

		const char *ptr = p->getWordDataPtr()->getWordPointer();
		WordData *ptr2 = p->getWordDataPtr();
		//
		while (c <= toupper(*ptr)) {
			out << "<" << static_cast<char>(c) << ">" << endl;
			c++;
		}
		//
		out << setw(15) << right << *ptr2;
		out << " ";
		out << "(" << p->getWordDataPtr()->getFreq() << ")" << " ";
		p->print(out);
		out << endl;

		p = p->getNext();
	}
	while (c <= 'Z') {
		out << "<" << static_cast<char>(c) << ">" << endl;
		c++;
	}
}

WordList::WordList(WordList &list) {
	this->head = list.head;
	this->tail = list.tail;
}

void WordList::operator=(WordList &list) {
	this->head = list.head;
	this->tail = list.tail;
}

int WordList::getSize() {
	return size;
}