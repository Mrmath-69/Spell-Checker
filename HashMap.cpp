#include "HashMap.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

using namespace std;
hashMap::hashMap() {
    for (int i = 0; i < 6673; ++i) {
        lists[i] = nullptr;
    }
}

hashMap::~hashMap() {
    for (int i = 0; i < 6673; ++i) {
        if (lists[i] != nullptr) {
            delete lists[i];
        }
    }
}

bool hashMap::contains(string word) {
    if(lists[calcHash(word)] == nullptr) {
        return false;
    }
    return lists[calcHash(word)]->contains(word);
}

void hashMap::addKeyValue(string word) {
    if(lists[calcHash(word)] == nullptr) {
        lists[calcHash(word)] = new SLL(word);
    } else {
        lists[calcHash(word)]->push(word);
    }
}

int hashMap::calcHash(string k) {
    int sum = 0;
    for (int i = 0; i < k.length(); i++) {
        sum += static_cast<int>(k[i]) *(31 * (i*i));
    }
    return sum % 6673;
}

void hashMap::removeWord(string word) {
    lists[calcHash(word)]->remove(word);
}

void hashMap::printMap() {
    for (int i = 0; i < 6673; i++) {
        cout << i << ": ";
        if (lists[i] != NULL) {
            lists[i]->printList();
        }
        cout << endl;
    }
}

void hashMap::documentFileForUser() {
    string fileName;
    cout << "Enter Full File (name and path): ";
    cin >> fileName;
    ifstream theFile(fileName);
    string line;
    bool allWordsInDictionary = true;
    while (getline(theFile, line)) {
        istringstream stream(line);
        string word;
        while (stream >> word) {
        if(lists[calcHash(word)] == nullptr || !lists[calcHash(word)]->contains(word)) {
            allWordsInDictionary = false;
            int number;
            this->spellChecker(word);
            cout << "\n" << endl;
            cout << word << " is either misspelled or it is not in our dictionary yet.\n Would you like to\n1. Push word into our dictionary so this doesn't happen again\n2. Word is indeed misspelled." << endl;
            while(true) {
                if(lists[calcHash(line)] == nullptr) {
                    cin >> number;
                    if(number == 1) {
                        lists[calcHash(line)] = new SLL(line);
                        cout << word << " Added" << endl;
                        break;
                    }
                    else if(number == 2) {
                        cout << word << " Not added" << endl;
                        break;

                    }
                    else {
                        cout << "Enter 1 or 2: ";
                        cin >> number;
                    }
                }
                else{
                    cin >> number;
                    if(number == 1) {
                        lists[calcHash(word)]->push(word);
                        cout << word << " Added" << endl;
                        break;
                    }
                    else if(number == 2) {
                        cout << word << " Not added" << endl;
                        break;

                    }
                    else {
                        cout << "Enter 1 or 2: ";
                        cin >> number;
                    }
                }
            }
            }
        }
    }
    if(allWordsInDictionary == true) {
        cout << "no spelling errors were detected." << endl;
    }
}

void hashMap:: saveDictionary() {
    string fileName;
    std::cout << "Enter file name to save: (Whole path)";
    cin >> fileName;
    int number = 0;
    while(number < 6673) {
        if (lists[number] != nullptr) {
            lists[number]->saveToFile(fileName);
        }
        number++;
    }
}

void hashMap::spellChecker(string word) {
    int number = 0;
    SLL *returnedList = new SLL();
    cout <<"Algorithm running..."<<endl;
    while (number < 6673) {
        if (lists[number] != nullptr) {
            (lists[number]->checkBucket(word, returnedList));
        }
        number++;
        if (number % 100 == 0) {
            cout << "Spell checker at " << ((number * 1.0)/6673)*100 << "% for " << word<<endl;
        }
    }
    cout << "Spell checker done for " << word<<endl;
    cout << "Here are the possible words you may have meant to spell:" << endl;
    returnedList->printList();
    cout << "\n" << endl;
}