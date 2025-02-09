/**
 * @file Vector.cpp
 * @author Justin Marlow
 * @date 2025-02-08
 * @brief Implementation of Vector class
 * 
 * Implementation file for Vector class: a dynamic array similiar to std::vector
 */

#include "Vector.h"
#include <iostream>

using namespace std;
  
  /**
   * Default constructor: Initializes an empty Vector
   * 
   * @post - vec_ptr is nullptr;
   *       - vec_size is 0;
   *       - vec_capacity is 0;
   * 
   */
Vector::Vector() {
  vec_ptr = nullptr; // No memory allocated yet
  vec_size = 0;
  vec_capacity = 0;
}

  /**
   * Copy constructor that makes a deep copy of another Vector
   *
   * @param const Vector &other The other Vector object to copy
   * @post - A new independent array is allocated
   *       - vec_size and vec_capacity match 'other'
   *       - Contents of 'other' are copied into the new array
   * 
   */
Vector::Vector(const Vector &other) {
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;

  // Allocate new memory for deep copy
  vec_ptr = new int[vec_capacity];

  // Copy all elements
  for(int i = 0; i < vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i];
  }
}

  /**
   * Destructor that deallocates the memory and resets the vector
   *
   * @post - vec_ptr has been deallocated
   *       - vec_size is 0
   *       - vec_capacity is 0
   * 
   */
Vector::~Vector() {
  delete[] vec_ptr; // frees allocated memory
  vec_ptr = nullptr;
  vec_size = 0;
  vec_capacity = 0;
  cout << "Destructor called: Memory Freed." << "\n" << endl;
}

  /**
   * Overloaded assignment operator for deep copy
   *
   * @param const Vector &other The vector object to assign
   * @return Vector& Reference to modified Vector
   * @post - vec_ptr is initialized and its array contains other.vec_ptr's data
   *       - vec_size=other.vec_size and vec_capacity=other.vec_capacity
   * 
   */
Vector& Vector::operator=(const Vector &other) {
  if (this != &other) { // Prevents self-assignment
    // Free existing memory
    delete[] vec_ptr;
  }
  
    // copy size and capacity
    vec_size = other.vec_size;
    vec_capacity = other.vec_capacity;

    // Allocate new memory
    vec_ptr = new int[vec_capacity];

    // Copy elements
    for (int i = 0; i < vec_size; i++) {
      vec_ptr[i] = other.vec_ptr[i];
    }
    return *this;
}
  

  /**
   * Returns the current number of elements in the Vector
   *
   * @return int The current number of elements in the Vector 
   * 
   */
  int Vector::size() {
    return vec_size;
  }

  /**
   * Returns the currently allocated storage for the Vector
   *
   * @return int The currently allocated storage for the Vector. 
   * 
   */
  int Vector::capacity() {
    return vec_capacity;
  }
  

  /**
   * Stores new element on the end of the Vector
   *
   * @param int element The integer added to the end of the Vector 
   * @post - item element is stored at the end of the Vector
   *       - if necessary, calls reserve() before adding element.
   *         The reserve doubles the current capacity of the Vector
   *
   */
  void Vector::push_back(int element) {
    // If we are out of space, we must allocate more
    if (vec_size == vec_capacity) {
      // Double capacity
      int new_capacity = (vec_capacity == 0 ) ? 1 : vec_capacity * 2;
      reserve(new_capacity);
    }

    // Add element at the next available slot
    vec_ptr[vec_size] = element;
    vec_size++;
  }


  /**
   * Requests that the Vector capacity be resized to at least enough to contain 'n' elements
   *
   * @param unsigned int index The desired number of elements
   *
   * If 'n' is greater than current storage, the function causes the container to reallocate its
   * storage, increasing its capacity to at least 'n'.
   *
   * If 'n' is less than or equal to the current capacity, the call does nothing.
   *
   * This function has no effect on the vector size and cannot alter its elements.
   *
   * @post - Vector has a capacity of at least 'n' and the size remains the same. 
   * 
   */
  void Vector::reserve(int n) {
    if (n > vec_capacity) {
      int* new_ptr = new int[n]; // Allocates new memory

      // Copy existing elements
      for (int i = 0; i < vec_size; i++) {
	new_ptr[i] = vec_ptr[i];

      }

      // Free old memory
      delete[] vec_ptr;

      // Update pointer and capacity
      vec_ptr = new_ptr;
      vec_capacity = n;
    }
  }

  

/**
 * Overloaded operator for element access
 *
 * @param unsigned int index The index of the element to access. 
 * @return int& Reference to element as 'index'
 * 
 */
  int& Vector::operator[](unsigned int index) {
    return vec_ptr[index]; // Direct access
  }

