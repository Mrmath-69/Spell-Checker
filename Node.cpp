#include "Node.hpp"

Node::Node() {
    word = "";
    next = nullptr;
}

Node::Node(string word) {
    this->word = word;
    next = nullptr;
}

void Node::printNode() {
    cout << word << "\n";
}