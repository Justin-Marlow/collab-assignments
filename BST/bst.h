/**
 * @file BST.h
 * @brief Declares the Binary Search Tree (BST) class for storing string-integer pairs.
 *
 * The BST class allows fast insertion, lookup, deletion, and ordered traversal of (key, value) pairs.
 * Keys are strings and must be unique. Values are integers.
 *
 * @author Justin Marlow
 */


#ifndef BST_H
#define BST_H

#include <string>
#include <fstream>

/**
 * @class BST
 * @brief Custom binary search tree that maps string keys to integer values.
 */
class BST {
private:
    struct Node;
    Node* root;

    // Internal helper methods
    Node* insert(Node* node, const std::string& key, int value);
    Node* remove(Node* node, const std::string& key);
    Node* find(Node* node, const std::string& key);
    void printInOrder(Node* node);
    void saveToFile(Node* node, std::ofstream& file);
    Node* minNode(Node* node);
    Node* maxNode(Node* node);
    void destroyTree(Node* node);

public:
    /**
     * @brief Default constructor. Initializes an empty BST.
     */
    BST();

    /**
     * @brief Destructor. Frees all dynamically allocated nodes.
     */
    ~BST();

    /**
     * @brief Adds or updates a key/value pair in the tree.
     * @param key The string key to insert or update
     * @param value The value associated with the key
     */
    void set(const std::string& key, int value);

    /**
     * @brief Searches the tree for a given key.
     * @param key The key to search for
     * @return The integer value associated with the key, or 0 if not found
     */
    int find(const std::string& key);

    /**
     * @brief Prints all (key, value) pairs in order.
     */
    void print();

    /**
     * @brief Prints the (key, value) pair with the smallest key.
     */
    void min();

    /**
     * @brief Prints the (key, value) pair with the largest key.
     */
    void max();

    /**
     * @brief Saves the contents of the BST to a file in-order.
     * @param filename The name of the output file
     */
    void save_file(const std::string& filename);

    /**
     * @brief Deletes the node with the specified key from the tree.
     * @param key The key of the node to delete
     */
    void delete_key(const std::string& key);

    /**
     * @brief Overloaded operator[] for access or insertion.
     *        If key doesn't exist, a new node is inserted with value 0.
     * @param key The key to access or insert
     * @return A reference to the integer value associated with the key
     */
    int& operator[](const std::string& key);
};

#endif
