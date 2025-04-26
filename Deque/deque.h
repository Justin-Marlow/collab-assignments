/**
 * @file deque.h
 * @author Odin's Ravens
 * @date April 25, 2025
 * @brief Header file for the Deque class.
 * 
 * This file contains the class definition for a custom Deque (double-ended queue)
 * implemented using a dynamic double array (2D array) called blockmap.
 * This class supports efficient push and pop operations from both ends,
 * indexed access via operator[], and dynamic resizing as needed.
 * 
 * Course: CSCI 325 — Data Structures and Algorithms
 */

#ifndef DEQUE_H
#define DEQUE_H

/**
 * @class Deque
 * @brief A double-ended queue (deque) implemented using a dynamic double array.
 * 
 * Supports push/pop from both front and back, indexed access, and dynamic resizing.
 */
class Deque {
private:
    // Number of elements per block in the blockmap
    static const int BLOCK_SIZE = 64;

    // Pointer to a dynamic array of integer pointers (2D array)
    int** blockmap;

    // Number of blocks that the blockmap can currently hold
    int blockmapCapacity;

    // Index of the block where the front element is located
    int frontBlock;

    // Index of the block where the back element is located
    int backBlock;

    // Index within the front block where the front element starts
    int frontIndex;

    // Index within the back block where the back element ends
    int backIndex;

    // Total number of elements in the deque
    int count;

    /**
     * @brief Grows the deque from the front by allocating a new block if needed.
     */
    void growFront();

    /**
     * @brief Grows the deque from the back by allocating a new block if needed.
     */
    void growBack();

    /**
     * @brief Resizes the blockmap if more blocks are needed (front or back).
     */
    void resizeBlockmap();

public:
    /**
     * @brief Constructs an empty deque.
     */
    Deque();

    /**
     * @brief Destructor. Frees all dynamically allocated memory.
     */
    ~Deque();

    /**
     * @brief Adds an element to the front of the deque.
     * @param value The integer value to add.
     */
    void push_front(int value);

    /**
     * @brief Adds an element to the back of the deque.
     * @param value The integer value to add.
     */
    void push_back(int value);

    /**
     * @brief Removes the front element from the deque.
     */
    void pop_front();

    /**
     * @brief Removes the back element from the deque.
     */
    void pop_back();

    /**
     * @brief Gets a copy of the front element.
     * @return The value at the front of the deque.
     */
    int front() const;

    /**
     * @brief Gets a copy of the back element.
     * @return The value at the back of the deque.
     */
    int back() const;

    /**
     * @brief Checks whether the deque is empty.
     * @return True if the deque is empty; false otherwise.
     */
    bool empty() const;

    /**
     * @brief Gets the current number of elements in the deque.
     * @return The number of stored elements.
     */
    int size() const;

    /**
     * @brief Accesses the element at a specific index.
     * @param index Index of the element (0-based).
     * @return Reference to the element at that index.
     */
    int& operator[](int index);
};

#endif
