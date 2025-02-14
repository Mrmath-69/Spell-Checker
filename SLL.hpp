#ifndef SLL_HPP_
#define SLL_HPP_

#include <iostream>
#include "Node.hpp"

using namespace std;

class SLL {
	Node *first;
	Node *last;

public:
	SLL();  // constructor - initializes an empty list
	SLL(string word); // constructor initializes a list with one node
	~SLL(); // destructor
	void push(string word); // adds a word to the list
	int remove(string word); // removes the word from the list
	bool contains(string word); // returns true if the word is in the list, false otherwise
	void printList(); // prints the entire list
	void saveToFile(string fileName);
	int levenshteinRecursive(const string& str1, const string& str2, int m, int n);
	void checkBucket(string word, SLL* returnedList);
};

#endif /* SLL_HPP_ */