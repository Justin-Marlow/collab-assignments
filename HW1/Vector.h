/**
 * @file Vector.h
 * @author Justin Marlow
 * @date 2025-02-08
 * @brief header file for Vector class
 * 
 * Header file for Vector class: a dynamic array similiar to std::vector
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/**
 * A dynamic array similiar to std::vector
 *
 * @class Vector Vector.h "HW1/Vector.h"
 * @brief A dynamic array similiar to std::vector
 *
 */
class Vector {
private:
  int* vec_ptr; // points to vector's dynamic array of integers
  int vec_size, vec_capacity; // same as size and capacity for std::vector

public:  
  /**
   * Construct a new empty Vector object
   * 
   * @post - vec_ptr is NULL;
   *       - vec_size is 0;
   *       - vec_capacity is 0;
   * 
   */
  Vector();  

  /**
   * Copy constructor that makes a deep copy of another Vector
   *
   * @param const Vector &other The other Vector object to copy
   * @post - vec_ptr is initialized
   *       - vec_size=other.vec_size
   *       - vec_capacity=other.vec_capacity
   * 
   */
  Vector(const Vector &other);

  /**
   * Destructor that deallocates the memory and resets the vector
   *
   * @post - vec_ptr has been deallocated
   *       - vec_size is 0
   *       - vec_capacity is 0
   * 
   */
  ~Vector();

  /**
   * Overloaded assignment operator for deep copy
   *
   * @param const Vector &other The vector object to assign
   * @return Vector& Reference to modified Vector
   * @post - vec_ptr is initialized and its array contains other.vec_ptr's data
   *       - vec_size=other.vec_size and vec_capacity=other.vec_capacity
   * 
   */
  Vector& operator=(const Vector &other);

  /**
   * Returns the current number of elements in the Vector
   *
   * @return int The current number of elements in the Vector 
   * 
   */
  int size();

  /**
   * Returns the currently allocated storage for the Vector
   *
   * @return int The currently allocated storage for the Vector. 
   * 
   */
  int capacity();


  /**
   * Stores new element on the end of the Vector
   *
   * @param int element The integer added to the end of the Vector 
   * @post - item element is stored at the end of the Vector
   *       - if necessary, calls reserve() before adding element.
   *         The reserve doubles the current capacity of the Vector
   *
   */
  void push_back(int element);


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
  void reserve(int n);

  

  /**
   * Overloaded operator for element access
   *
   * @param unsigned int index The index of the element to access. 
   * @return int& Reference to element as 'index'
   * 
   */
  int& operator[](unsigned int index);
  
};

#endif // VECTOR_H
