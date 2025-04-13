/**
 * @file Node.cpp
 * @brief Implements the Node class constructor and destructor.
 *
 * @author Justin Marlow
 */


#include "node.h"

/**
 * @brief Node constructor.
 * Initializes the node with key and value, sets left and right to nullptr.
 * 
 * @param k The key used for sorting.
 * @param d The data stored at this node. Defaults to 1.
 */
Node::Node(std::string k, int d) {
    key = k;
    data = d;
    left = nullptr;
    right = nullptr;
}

/**
 * @brief Node destructor.
 *
 */
Node::~Node() {

}
