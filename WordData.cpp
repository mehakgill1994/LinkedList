#include <cassert>
#include "WordData.h"

WordData::WordData() {

}

WordData::WordData(char word[], int lineNum) {
	//cannot use sizeof() here, as when we pass an array as an argument to a function, it decays to a pointer
	//sizeof() can only be used in the same scope where the array is declared
	//int len = sizeof(word)/sizeof(char);
	
	int len = 0;
	while (word[len] != '\0') {
		len++;
	}
	this->word = new char[len+1];	
	for (int i = 0; i < len+1; i++) {
		this->word[i] = tolower(word[i]);
	}
	this->list.add(lineNum);
	this->freq = (this->freq)+1;
}

WordData::WordData(WordData &data) {
	int len = 0;
	const char* ptr = data.getWordPointer();
	const char* temp = data.getWordPointer();
	while (*temp != '\0') {
		len++;
		temp++;
	}
	word = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		this->word[i] = tolower(ptr[i]);
	}
	this->freq = data.freq;
	this->list = data.list;
}

void WordData::operator=(WordData &data) {
	if (this == &data)
		return;
//	delete[] word;
	int len = 0;
	const char* ptr = data.getWordPointer();
	const char* temp = data.getWordPointer();
	while (*temp != '\0') {
		len++;
		temp++;
	}
	word = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		this->word[i] = ptr[i];
	}
	this->freq = data.freq;
	this->list = data.list;
}

WordData::~WordData() {
	delete[] word;
}

int WordData::getFreq() {
	return freq;
}

const char* WordData::getWordPointer() {
	return word;
}

NumList& WordData::getList(){
	return list;
}

int WordData::compare(char* word1) const{
	char *temp = this->word;
	char *word = word1;

	while (*temp != '\0' || *word != '\0') {

		if (*temp == tolower(*word)) {
			word = word + 1;
			temp = temp + 1;
		}
		else if (*temp < tolower(*word))
			return -1;
		else if(*temp > tolower(*word))
			return 1;
	}
	if (*temp == '\0' && *word == '\0')
		return 0;
	else if (*temp == '\0')
		return -1;
	else
		return 1;
}

std::ostream &operator<<(std::ostream &out, const WordData &data) {
	//out << "word: ";
	out << data.word;
	/*int i = 0;
	while (data.word[i] != '\0') {
		out << data.word[i];
	}*/
	//out << std::endl;
	//out << "frequency: " << data.freq<< std::endl;
	//out << "line number: ";
	//int linenumsize = data.list.getsize();
	//int j;
	//for (j = 0; j < linenumsize-1; j++) {
	//	out << data.list.get(j) << ",";
	//}
	//out << data.list.get(j) << std::endl;*/
	return out;
}

void WordData::incrementFreq() {
	freq++;
}