#include <iostream>
#include <fstream>
#include "NumList.h"
#include "WordData.h"
#include "WordList.h"
using namespace std;

int main(){

	WordList w1("input.txt");
	
	//writing output to file
	ofstream fout;
	fout.open("output.txt");
	fout << w1;

	//writing output to console
	w1.print(cout);
	
	return 0;
}