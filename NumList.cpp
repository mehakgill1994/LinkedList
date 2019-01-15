#include <cassert>
#include "NumList.h"

NumList::NumList(){
	capacity = 1;
	store = new int[capacity];
	size = 0;
}

NumList::NumList(const NumList &listToBeCopied){
	size = listToBeCopied.size;
	capacity = listToBeCopied.capacity;
	store = new int[capacity];
	for (int k = 0; k < size; k++) {
		store[k] = listToBeCopied.store[k];
	}
}

void NumList::operator=(const NumList &listToBeCopied) {
	if (this == &listToBeCopied)
		return;
	delete[] store;
	size = listToBeCopied.size;
	capacity = listToBeCopied.capacity;
	store = new int[capacity];
	for (int k = 0; k < size; k++) {
		store[k] = listToBeCopied.store[k];
	}
}

NumList::~NumList() {
	delete[] store;
}

bool NumList::isEmpty() {
	return size == 0;
}

bool NumList::isPresent(int val) {
	for (int k = 0; k < this->size; k++) {
		if (store[k] == val)
			return true;
	}
	return false;
}

void NumList::add(int val) {
	//checking if the element is already present in the list 
	if (!isPresent(val)) {
		//checking if full
		if (size == capacity) {
			NumList temp = *this;
			delete[] store;
			capacity = 2 * temp.capacity;
			store = new int[capacity];
			for (int k = 0; k < temp.size; k++) {
				store[k] = temp.store[k];
			}
		}
		store[size] = val;
		size++;
	}
}

int NumList::get(int index) const{
	return store[index];
}

void NumList::set(int index, int val) {
	store[index] = val;
}

int NumList::getSize() const {
	return size;
}

const int* NumList::getPointer() {
	return store;
}