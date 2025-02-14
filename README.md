# Spell Checker using Hash Map

## Overview

This C++ program implements a spell checker using a hash map. The program loads a dictionary from a file, allows users to check and correct words, add/remove words, and perform spell-checking on files.

## Features

- **Print Dictionary**: Display all words in the dictionary.
- **Check for a Word**: Verify if a word exists in the dictionary.
- **Add a Word**: Insert a new word into the dictionary.
- **Remove a Word**: Delete a word from the dictionary.
- **Spell Check a File**: Analyze a file and suggest corrections for misspelled words.
- **Save Dictionary**: Save the updated dictionary to a file.

## Installation

1. Clone the repository or download the source code.
2. Ensure you have a C++ compiler installed (e.g., g++).
3. Place your dictionary file (`5000_Dictionary.txt`) in the project directory.
4. Compile the program:
   ```sh
   g++ mainHash.cpp hashMap.cpp SLL.cpp node.cpp -o spell_checker
   ```

## Usage

1. Run the program:
   ```sh
   ./spell_checker
   ```
2. Follow the on-screen menu options to interact with the spell checker.

## File Structure

```
├── mainHash.cpp            # Main program file
├── hashMap.cpp             # Hash map implementation
├── HashMap.hpp             # Hash map header file
├── SLL.cpp                 # Singly linked list implementation
├── SLL.hpp                 # Singly linked list header file
├── node.cpp                # Node implementation
├── Node.hpp                # Node header file
├── 5000_Dictionary.txt     # Dictionary file (word list)
├── README.md               # Project documentation
```

## Data Structures

- **HashMap**: Used to efficiently store and retrieve dictionary words.
- **Singly Linked List (SLL)**: Each hash bucket is implemented using a linked list for handling collisions.
- **Levenshtein Distance Algorithm**: Used for spell-checking by finding the closest word matches.

## Node Class

The `Node` class is used to represent each element in the singly linked list. It contains a word and a pointer to the next node.

## SLL Class and Methods

The `SLL` class represents a singly linked list. It includes the following methods:
- **push**: Adds a word to the list.
- **remove**: Removes a word from the list.
- **contains**: Checks if a word is in the list.
- **printList**: Prints all words in the list.
- **saveToFile**: Saves the list to a file.
- **levenshteinRecursive**: Calculates the Levenshtein distance between two words.
- **checkBucket**: Checks for similar words in the list.

## HashMap Methods

- **documentFileForUser**: Analyzes a file and suggests corrections for misspelled words.
- **spellChecker**: Finds the closest word matches for a given word.
- **removeWord**: Deletes a word from the hash map.
- **saveDictionary**: Saves the updated dictionary to a file.

## License

This project is open-source and available for modification and distribution.

## Author

- Eric Jackson

