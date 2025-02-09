/**
 * @file main.cpp
 * @author Justin Marlow
 * @date 2025-02-08
 * @brief  Tests to verify Vector class functionality
 * 
 * Test file to verify Vector Class functionality
 */


#include <iostream>
#include "Vector.h"

using namespace std;

/**
 * Test for Default constructor
 * 
 */
void test_constructor();

/**
 * Test for push_back(), size(), capacity(), and operator[]
 * 
 */
void test_push_back_and_access();

/**
 * Test for copy constructor
 * 
 */
void test_copy_constructor();
/**
 * Test for assignment operator
 * 
 */
void test_assignment_operator();

/**
 * Test for reserve()
 * 
 */
void test_reserve();

/**
 * Test for large insertion
 * 
 */
void test_large_insertion();


int main() {
  test_constructor();
  test_push_back_and_access();
  test_copy_constructor();
  test_assignment_operator();
  test_reserve();
  test_large_insertion();

  cout << "All test completed!" << endl;
  
  return 0;
}


/**
 * Test for Default constructor
 * 
 */
void test_constructor(){
  cout << "Test 1: Default Constructor" << endl;
  Vector v;
  cout << "Initial size: " << v.size() << ", capacity: " << v.capacity() << "\n" << endl;
}

/**
 * Test for push_back(), size(), capacity(), and operator[]
 * 
 */
void test_push_back_and_access(){
  cout << "Test 2: push_back(), size(), capacity(), and operator[]" << endl;
  Vector v;

  for (int i = 1; i <= 10; i++) {
    v.push_back(i * 10);
    cout << "Added " << i * 10 << " | Size: " << v.size() << " | Capacity: " << v.capacity() << endl;
  }

  cout << endl << "Checking operator[]:" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << "v[" << i << "] = " << v[i] << endl;
  }
  cout << endl;
}


/**
 * Test for copy constructor
 * 
 */
void test_copy_constructor() {
  cout << "Test 3: Copy Constructor" << endl;
  Vector v1;
  for (int i = 1; i <= 10; i++) {
    v1.push_back(i * 10);
  }

  Vector v2 = v1;   // deep copy
  v2.push_back(900);  // modify v2 to check deep copy

  cout << "v1 size: " << v1.size() << ", v2 size: " << v2.size() << endl;
  cout << "v1 last element: " << v1[v1.size() - 1] << ", v2 last element: " << v2[v2.size() - 1] << "\n" << endl;
}

/**
 * Test for assignment operator
 * 
 */
void test_assignment_operator() {
  cout << "Test 4: Assignment Operator" << endl;
  Vector v1;
  for (int i = 1; i <= 10; i++) {
    v1.push_back(i * 10);
  }

  Vector v2;
  v2 = v1; // deep copy via assignment
  v2.push_back(800); // modify v2 to check deep copy

  cout << "v1 size: " << v1.size() << ", v2 size: " << v2.size() << endl;
  cout << "v1 last element: " << v1[v1.size() - 1] << ", v2 last element: " << v2[v2.size() - 1] << "\n" << endl;
}


/**
 * Test for reserve()
 * 
 */
void test_reserve() {
  cout << "Test 5: Reserve Capacity" << endl;
  Vector v;
  v.reserve(500);
  cout << "After reserving 500: Capacity = " << v.capacity() << endl;
}

/**
 * Test for large insertion
 * 
 */
void test_large_insertion() {
  cout << "Test 6: Large Insertion Test (1000 elements)" << endl;
  Vector v;
  for (int i = 0; i < 1000; i++) {
    v.push_back(i);
  }
  cout << "Final size: " << v.size() << ", Final capacity: " << v.capacity() << "\n" << endl;
}
