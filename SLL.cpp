#include "SLL.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
#include <algorithm>
SLL::SLL() {
first = last = NULL;
}

SLL::SLL(string word) {
first = last = new Node(word);
}

SLL::~SLL() {
    Node* current = first;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

}

void SLL::push(string word) {
    if (!this->contains(word)) {
        Node* temp = first;
        first = new Node(word);
        first->next = temp;
    }
}

bool SLL::contains(string word) {
    Node* current = first;
    while (current != nullptr) {
        if(current->word == word) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int SLL::remove(string word) {
    if(contains(word)) {
        Node* current = first;
        while (current != nullptr) {
            if(first->word == word) {
                cout << "Word removed" << endl;
                first = first->next;
                break;
            }
            if(current->next == last) {
                current->next = NULL;
                last = current;
                cout << "Word removed" << endl;

                break;
            }
            if (current->next->word == word) {
                current->next = current->next;
                cout << "Word removed" << endl;

                break;
            }
            current = current->next;
        }
        return 0;
    }
    cout << "Word not found in dictionary" << endl;
    return -1;
    }

void SLL::printList() {
    Node *temp = first;
    while (temp != nullptr) {
        temp->printNode();
        temp = temp->next;
    }
}

void SLL::saveToFile(string fileName) {
    ofstream outFile(fileName, ios::app);
    Node* current = first;
    while (current != nullptr) {
        outFile << current->word << '\n';
        cout << current->word <<" saved to " << fileName << endl;
        current = current->next;
    }
    outFile.close();
}

int SLL:: levenshteinRecursive(const string& str1,
                        const string& str2, int m, int n)
{
    // str1 is empty
    if (m == 0) {
        return n;
    }
    // str2 is empty
    if (n == 0) {
        return m;
    }

    if (str1[m - 1] == str2[n - 1]) {
        return levenshteinRecursive(str1, str2, m - 1,n - 1);
    }
    return 1+ min(levenshteinRecursive(str1, str2, m, n - 1),min(levenshteinRecursive(str1, str2, m - 1,n),levenshteinRecursive(str1, str2, m - 1,n - 1)));
}
void SLL::checkBucket(string word, SLL* returnedList) {
    Node* current = first;
    while (current != nullptr) {
        int wordDist = word.length() - current->word.length();
        if (wordDist < 0) {
            wordDist = wordDist * -1;
        }
        if(wordDist <= 3) {
            int distance = levenshteinRecursive(current->word, word, current->word.length(), word.length());
            if (distance <= 2){
                returnedList->push(current->word);
            }
        }
        current = current->next;
    }
}


