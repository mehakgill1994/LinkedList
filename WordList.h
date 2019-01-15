#ifndef WORDLIST_H
#define WORDLIST_H

#include "WordData.h"
#include <string>

class WordList {
private:
	struct WordNode
	{
	private:
		WordData data;
		WordNode* next;
	public:
		WordNode(char word[], int linNum) {
			this->next = nullptr;
			WordData temp(word, linNum);
			this->data = temp;
		}
		WordNode(char word[], int linNum, WordNode* next) {
			this->next = next;
			WordData temp(word, linNum);
			this->data = temp;

		}
		void setNext(WordNode* ptr) {
			next = ptr;
		}

		WordData* getWordDataPtr() {
			return &data;
		}

		WordNode* getNext() const {
			return next;
		}

		void print(std::ostream &out) {
			
			const NumList& ls = data.getList();
			for(int i = 0; i < ls.getSize(); i++)
				out << ls.get(i) << " ";
		}
	};
	WordNode *head, *tail;
	int size;

public:
	WordList();
	WordList(std::string fileName);
	WordList(WordList &list);
	void operator=(WordList &list);
	~WordList();
	int getSize();
	void print(std::ostream &out) const;
	friend std::ostream &operator<<(std::ostream &out, const WordList &list);
};

#endif