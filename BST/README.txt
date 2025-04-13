README - Binary Search Tree Project

Description:
------------
This project implements a custom Binary Search Tree (BST) in C++ for storing and managing key/value pairs. The tree is sorted by string keys, with integer values representing associated data (such as word frequencies). The implementation avoids the use of C++ STL containers like map and instead recreates the BST logic.

The program supports inserting, updating, deleting, and searching for keys, as well as printing the contents of the tree in sorted order. It also includes a bonus operator[] overload to allow array-like access to the tree.

A menu-based driver allows users to interact with the tree, manually insert keys, or load and process an external text file for word counting.

Files Included:
---------------
- driver.cpp        : Menu-driven interface for interacting with the BST
- BST.h / BST.cpp   : Implementation of the Binary Search Tree class
- Node.h / Node.cpp : Definition of the Node class used in the BST
- test.dat          : Sample input file for testing word count
- Makefile          : Used to compile the project
- README            : This file

How to Build:
-------------
To build the program, run the following command in the project folder:
make

How to Run:
-----------
To run the compiled program:
./bst

Menu Options:
-------------
1. Set key/value	     		  	- Manually add or update a key in the tree
2. Find value by key        	  	- Search for a specific key
3. Print all (key, value) pairs   	- Display all keys in order with values
4. Print minimum key   			  	- Show the key with the lowest alphabetical value
5. Print maximum key				- Show the key with the highest alphabetical value
6. Save tree to file        		- Save all (key, value) pairs to a text file
7. Delete key                		- Remove a specific key from the tree
8. Count words from file     		- Read a file and build the tree with word frequencies
0. Exit                      		- Quit the program

Notes:
------
- The tree is sorted alphabetically by key (case-sensitive).
- When reading from a file, all words are normalized by removing punctuation and converting to lowercase.
- The tree uses dynamic memory. The destructor ensures the entire structure is deleted on exit.
- File output is written in alphabetical order using in-order traversal.

Author:
-------
Justin Marlow
