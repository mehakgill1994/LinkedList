#ifndef NUMLIST_H
#define NUMLIST_H

class NumList{
private:
	int *store;
	int size;
	int capacity;
	void resize(){ capacity *= 2; };
public:
	NumList();
	NumList(const NumList &listToBeCopied);
	void operator=(const NumList &listToBeCopied);
	~NumList();

	bool isEmpty();
	bool isPresent(int val);
	void add(int val);
	int get(int index) const;
	void set(int index, int val);
	int getSize() const;
	const int* getPointer();
};

#endif