/**
 * @file Node.h
 * @brief Declares the Node class used in the Binary Search Tree.
 *
 * Each node stores a string key, an integer value, and pointers to left and right child nodes.
 * This class is used internally by the BST class to represent nodes in the tree.
 *
 * @author Justin Marlow
 */


#ifndef NODE_H
#define NODE_H

#include <string>

/**
 * @class Node
 * @brief Represents a single node in the binary search tree.
 *        Stores a string key and an integer value, with pointers to left and right children.
 */
class Node {
private:
    std::string key;
    int data;
    Node* left;
    Node* right;

public:
    /**
     * @brief Constructs a Node with a given key and optional value.
     * @param k The key (string) for sorting
     * @param d The data (integer) associated with the key. Defaults to 1.
     */
    Node(std::string k, int d = 1);

    /**
     * @brief Destructor for the Node.
     */
    ~Node();

    // BST class access to private members
    friend class BST;
};

#endif