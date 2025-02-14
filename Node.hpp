#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>

using namespace std;

class Node {
	friend class SLL;
	string word;
	Node *next;

public:
	Node();
	Node(string word);
public:
	void printNode();
};

#endif /* NODE_HPP_ */
