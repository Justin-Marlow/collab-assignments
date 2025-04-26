/**
 * @file deque.cpp
 * @author Odin's Ravens
 * @date April 25, 2025
 * @brief Implementation file for the Deque class.
 *
 * This file contains all method definitions for the Deque class
 * declared in deque.h. The deque uses a dynamic blockmap (2D array)
 * to support efficient operations at both ends.
 *
 * Course: CSCI 325 — Data Structures and Algorithms
 */

 #include "deque.h"
 #include <iostream>
 #include <cassert>
 
 using namespace std;
 
 Deque::Deque() {
     blockmapCapacity = 8;
     blockmap = new int*[blockmapCapacity];
 
     for (int i = 0; i < blockmapCapacity; ++i) {
         blockmap[i] = nullptr;
     }
 
     // Start in the middle to allow growing in both directions
     frontBlock = backBlock = blockmapCapacity / 2;
     blockmap[frontBlock] = new int[BLOCK_SIZE];
 
     frontIndex = BLOCK_SIZE / 2;
     backIndex = frontIndex - 1;
     count = 0;
 }
 
 Deque::~Deque() {
     for (int i = 0; i < blockmapCapacity; ++i) {
         delete[] blockmap[i];
     }
     delete[] blockmap;
 }
 
 void Deque::growFront() {
     if (frontIndex == 0) {
         if (frontBlock == 0) resizeBlockmap();
         if (blockmap[--frontBlock] == nullptr)
             blockmap[frontBlock] = new int[BLOCK_SIZE];
         frontIndex = BLOCK_SIZE;
     }
 }
 
 void Deque::growBack() {
     if (backIndex == BLOCK_SIZE - 1) {
         if (backBlock == blockmapCapacity - 1) resizeBlockmap();
         if (blockmap[++backBlock] == nullptr)
             blockmap[backBlock] = new int[BLOCK_SIZE];
         backIndex = -1;
     }
 }
 
 void Deque::resizeBlockmap() {
     int newCapacity = blockmapCapacity * 2;
     int** newBlockmap = new int*[newCapacity];
     for (int i = 0; i < newCapacity; ++i)
         newBlockmap[i] = nullptr;
 
     int offset = (newCapacity - blockmapCapacity) / 2;
     for (int i = 0; i < blockmapCapacity; ++i)
         newBlockmap[i + offset] = blockmap[i];
 
     frontBlock += offset;
     backBlock += offset;
     delete[] blockmap;
     blockmap = newBlockmap;
     blockmapCapacity = newCapacity;
 }
 
 void Deque::push_front(int value) {
     growFront();
     blockmap[frontBlock][--frontIndex] = value;
     count++;
 }
 
 void Deque::push_back(int value) {
     growBack();
     blockmap[backBlock][++backIndex] = value;
     count++;
 }
 
 void Deque::pop_front() {
     assert(!empty() && "pop_front() called on empty deque");
 
     frontIndex++;
     if (frontIndex == BLOCK_SIZE) {
         delete[] blockmap[frontBlock];
         blockmap[frontBlock++] = nullptr;
         frontIndex = 0;
     }
     count--;
 }
 
 void Deque::pop_back() {
     assert(!empty() && "pop_back() called on empty deque");
 
     backIndex--;
     if (backIndex < 0) {
         delete[] blockmap[backBlock];
         blockmap[backBlock--] = nullptr;
         backIndex = BLOCK_SIZE - 1;
     }
     count--;
 }
 
 int Deque::front() const {
     assert(!empty() && "front() called on empty deque");
     return blockmap[frontBlock][frontIndex];
 }
 
 int Deque::back() const {
     assert(!empty() && "back() called on empty deque");
     return blockmap[backBlock][backIndex];
 }
 
 bool Deque::empty() const {
     return count == 0;
 }
 
 int Deque::size() const {
     return count;
 }
 
 int& Deque::operator[](int index) {
     assert(index >= 0 && index < count && "operator[] out of bounds");
 
     int absolute = frontIndex + index;
     int blockOffset = absolute / BLOCK_SIZE;
     int withinBlock = absolute % BLOCK_SIZE;
     return blockmap[frontBlock + blockOffset][withinBlock];
 }
 