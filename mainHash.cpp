#include "HashMap.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;





int main() {
	hashMap map1;
	ifstream inputFile("/Users/mrmath69/Downloads/HashMapProject_Student/5000_Dictionary.txt");
	string line;
	while (getline(inputFile, line)) {
		if(map1.contains(line)) {
		}
		map1.addKeyValue(line);
	}
	inputFile.close();

	while(true) {
		cout << "Options:\n1. print dictionary\n2. Check for a word\n3. Add a word\n4. Remove Word\n5. Spell Check a file\n6. Save dictionary to a file\n7. exit"<< endl;
		int option;
		cin >> option;
		if (option == 1) {
			map1.printMap();
		}

		else if (option == 2) {
			cout << "Enter Word: ";
			string line;
			std::cin >> line;
			if(!map1.contains(line)) {
				cout << "Word not found\n" << endl;
				string answer;
				cout << "Would you like to run a spell checker on that word? y/n" << endl;
				cin >> answer;
				if(answer == "y") {
					map1.spellChecker(line);
				}
			}else {
				cout << "Word Found" << endl;
			}
		}else if(option == 3) {
			cout << "Enter Word: ";
			string line;
			cin >> line;
			map1.addKeyValue(line);
			cout << "Added" << endl;
		}

		else if (option == 4) {
			cout << "Enter Word: ";
			string line;
			std::cin >> line;
			map1.removeWord(line);
		}

		else if (option == 5) {
			map1.documentFileForUser();
		}
		else if (option == 6) {
			map1.saveDictionary();
		}
		else if (option == 7) {
			break;
		}
		else {
			cout << "Invalid Option: Please try again" << endl;
		}
	}
	return 0;
}
