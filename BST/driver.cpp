/**
 * @file driver.cpp
 * @brief Provides the main menu and user interaction for the binary search tree application.
 *
 * This file allows the user to test all major features of the BST class including:
 * - Adding and updating key/value pairs
 * - Searching for values
 * - Printing the BST contents
 * - Saving to a file
 * - Deleting keys
 * - Counting words from a text file
 *
 * The interface is text-based and menu-driven for easy testing.
 * Words imported from files are sanitized and counted using the BST structure.
 *
 * @author Justin Marlow
 */


 #include "bst.h"
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <cctype>
 #include <algorithm>
 
 /**
  * @brief Cleans a word by removing unwanted punctuation and converting to lowercase.
  * @param word The input word to sanitize.
  */
 void cleanWord(std::string& word) {
     word.erase(std::remove_if(word.begin(), word.end(),
                [](char c) { return !std::isalnum(c) && c != '\''; }),
                word.end());
     std::transform(word.begin(), word.end(), word.begin(), ::tolower);
 }
 
 /**
  * @brief Loads a file and populates the BST with word frequencies.
  * @param tree Reference to the BST instance.
  * @param filename The name of the file to read words from.
  */
 void wordCountFromFile(BST& tree, const std::string& filename) {
     std::ifstream file(filename);
     if (!file.is_open()) {
         std::cout << "Error: Unable to open file '" << filename << "'.\n";
         return;
     }
 
     std::string word;
     int wordCount = 0;
     while (file >> word) {
         cleanWord(word);
         if (!word.empty()) {
             tree[word]++;
             ++wordCount;
         }
     }
 
     file.close();
     std::cout << "File '" << filename << "' loaded successfully. "
               << wordCount << " words processed.\n";
 }
 
 int main() {
     BST tree;
     int choice;
     std::string key, filename;
     int value;
 
     do {
         std::cout << "\n=== Binary Search Tree Menu ===\n"
                   << "1. Set key/value\n"
                   << "2. Find value by key\n"
                   << "3. Print all (key, value) pairs\n"
                   << "4. Print minimum key\n"
                   << "5. Print maximum key\n"
                   << "6. Save tree to file\n"
                   << "7. Delete key\n"
                   << "8. Count words from file\n"
                   << "0. Exit\n"
                   << "Enter your choice: ";
         std::cin >> choice;
 
         std::cout << "----------------------------------------\n";
 
         switch (choice) {
             case 1:
                 std::cout << "Enter key to insert/update: ";
                 std::cin >> key;
                 cleanWord(key);
                 std::cout << "Enter value: ";
                 std::cin >> value;
                 tree.set(key, value);
                 std::cout << "Key \"" << key << "\" was set to value " << value << ".\n";
                 break;
 
             case 2:
                 std::cout << "Enter key to find: ";
                 std::cin >> key;
                 value = tree.find(key);
                 if (value == 0)
                     std::cout << "Key \"" << key << "\" was not found in the tree.\n";
                 else
                     std::cout << "Found: (" << key << ", " << value << ")\n";
                 break;
 
             case 3:
                 std::cout << "Printing all (key, value) pairs in order:\n";
                 tree.print();
                 break;
 
             case 4:
                 std::cout << "Finding the minimum key in the tree:\n";
                 tree.min();
                 break;
 
             case 5:
                 std::cout << "Finding the maximum key in the tree:\n";
                 tree.max();
                 break;
 
             case 6:
                 std::cout << "Enter filename to save the tree to: ";
                 std::cin >> filename;
                 tree.save_file(filename);
                 break;
 
             case 7:
                 std::cout << "Enter key to delete from the tree: ";
                 std::cin >> key;
                 tree.delete_key(key);
                 std::cout << "Delete operation attempted for key \"" << key << "\".\n";
                 break;
 
             case 8:
                 std::cout << "Enter the name of the text file to analyze: ";
                 std::cin >> filename;
                 wordCountFromFile(tree, filename);
                 break;
 
             case 0:
                 std::cout << "Exiting program. Goodbye!\n";
                 break;
 
             default:
                 std::cout << "Invalid selection. Please enter a number between 0 and 8.\n";
                 break;
         }
 
         std::cout << "----------------------------------------\n";
 
     } while (choice != 0);
 
     return 0;
 }
 