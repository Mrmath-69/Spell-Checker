#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include <iostream>
#include "SLL.hpp"

class hashMap {
	SLL* lists[6673];

public:
	hashMap(); // constructor initializes an empty array
	~hashMap();
	void addKeyValue(string word); // calls the calcHash function and pushes the word into the linked list at array index returned by calcHash.
	bool contains(string word); // returns true if the word is in the map, false otherwise
	int calcHash(string word); // returns the hash value of the word, try to use a hash function that creates the best spread of words
	void printMap(); // prints the entire map array by index line by line
	void removeWord(string word);
	void documentFileForUser();
	void saveDictionary();
	void spellChecker(string word);
};

#endif /* HASHMAP_HPP_ */