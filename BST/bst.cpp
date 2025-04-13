/**
 * @file BST.cpp
 * @brief Implements the Binary Search Tree (BST) class.
 *
 * @author Justin Marlow
 */


#include "bst.h"
#include <iostream>
#include <fstream>

/**
 * @struct BST::Node
 * @brief Internal struct used to represent a node in the bst.
 */
struct BST::Node {
    std::string key; // key for sorting
    int data;        // associated data value
    Node* left;      // left child pointer
    Node* right;     // right child pointer

    Node(const std::string& k, int d = 1) : key(k), data(d), left(nullptr), right(nullptr) {}
};

/**
 * @brief Constructor for BST. Initializes an empty tree.
 */
BST::BST() : root(nullptr) {}

/**
 * @brief Destructor for BST. Destroys the entire tree.
 */
BST::~BST() {
    destroyTree(root);
}

/**
 * @brief Recursively frees all nodes
 * @param node starting node for deletion
 */
void BST::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/**
 * @brief Inserts or updates new key-value pair into the tree
 * @param node the current node
 * @param key the key to insert
 * @param value the associated value
 * @return the modified node pointer
 */
BST::Node* BST::insert(Node* node, const std::string& key, int value) {
    if (!node) return new Node(key, value);
    if (key < node->key) node->left = insert(node->left, key, value);
    else if (key > node->key) node->right = insert(node->right, key, value);
    else node->data = value; // Overwrite existing key
    return node;
}

/**
 * @brief insert or update a key/value pair
 */
void BST::set(const std::string& key, int value) {
    root = insert(root, key, value);
}

/**
 * @brief Finds and returns the value for a given key.
 * @return The value if found, otherwise 0.
 */
int BST::find(const std::string& key) {
    Node* curr = root;
    while (curr) {
        if (key == curr->key) return curr->data;
        else if (key < curr->key) curr = curr->left;
        else curr = curr->right;
    }
    return 0; // not found
}

/**
 * @brief print the entire BST in-order
 */
void BST::print() {
    printInOrder(root);
}

/**
 * @brief Internal recursive function to print the tree in-order.
 */
void BST::printInOrder(Node* node) {
    if (!node) return;
    printInOrder(node->left);
    std::cout << "(" << node->key << ", " << node->data << ")" << std::endl;
    printInOrder(node->right);
}

/**
 * @brief Prints the minimum (leftmost) node in the tree.
 */
void BST::min() {
    Node* minN = minNode(root);
    if (minN) std::cout << "(" << minN->key << ", " << minN->data << ")" << std::endl;
}

/**
 * @brief Prints the maximum (rightmost) node in the tree.
 */
void BST::max() {
    Node* maxN = maxNode(root);
    if (maxN) std::cout << "(" << maxN->key << ", " << maxN->data << ")" << std::endl;
}

/**
 * @brief Saves the BST contents to a file in in-order traversal.
 * @param filename The output filename
 */
void BST::save_file(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    saveToFile(root, outFile);
    outFile.close();
    std::cout << "Tree saved to file: " << filename << "\n";
}

/**
 * @brief Recursive helper to write the tree in order to a file.
 * 
 * @param node Current node in traversal.
 * @param file Reference to the open output file stream.
 */
void BST::saveToFile(Node* node, std::ofstream& file) {
    if (!node) return;
    saveToFile(node->left, file);
    file << node->key << " " << node->data << std::endl;
    saveToFile(node->right, file);
}

/**
 * @brief Deletes a node with the given key.
 * @param key The key to remove.
 */
void BST::delete_key(const std::string& key) {
    root = remove(root, key);
}

/**
 * @brief Recursive helper to delete a node by key.
 * @param node The subtree root
 * @param key The key to delete
 * @return Updated subtree root after deletion
 */
BST::Node* BST::remove(Node* node, const std::string& key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        // Node with matching key found
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        else if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* minRight = minNode(node->right);
            node->key = minRight->key;
            node->data = minRight->data;
            node->right = remove(node->right, minRight->key);
        }
    }
    return node;
}

/**
 * @brief Returns the node with the smallest key in a subtree.
 */
BST::Node* BST::minNode(Node* node) {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
}

/**
 * @brief Returns the node with the largest key in a subtree.
 */
BST::Node* BST::maxNode(Node* node) {
    if (!node) return nullptr;
    while (node->right) node = node->right;
    return node;
}

/**
 * @brief Overloaded operator[] for associative array-style access.
 *        If the key doesn't exist, inserts it with value 0 and returns a reference.
 * 
 * @param key The key to access
 * @return Reference to the associated value
 */
int& BST::operator[](const std::string& key) {
    Node* curr = root;
    Node* parent = nullptr;

    while (curr) {
        if (key == curr->key)
            return curr->data;
        parent = curr;
        if (key < curr->key) curr = curr->left;
        else curr = curr->right;
    }

    // If not found, insert a new node with value 0
    Node* newNode = new Node(key, 0);
    if (!parent) root = newNode;
    else if (key < parent->key) parent->left = newNode;
    else parent->right = newNode;

    return newNode->data;
}
