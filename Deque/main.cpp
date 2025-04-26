/**
 * @file main.cpp  
 * @author Odin's Ravens  
 * @date April 25, 2025  
 * @brief Automated and interactive test harness ("Deque Gauntlet")  
 * 
 * This test driver runs a user-defined number of operations on a custom Deque and compares
 * each one to std::vector as a reference. After an initial dry run, it offers reproducible or
 * new random test options based on the previously used seed.
 * 
 * Course: CSCI 325 — Data Structures and Algorithms  
 */

 #include <iostream>
 #include <vector>
 #include <cstdlib>
 #include <ctime>
 #include <cassert>
 #include "deque.h"
 
 using namespace std;
 
 enum Operation {
     PUSH_FRONT,
     PUSH_BACK,
     POP_FRONT,
     POP_BACK,
     ACCESS_INDEX
 };
 
 Operation randomOperation() {
     int r = rand() % 100;
     if (r < 30) return PUSH_BACK;
     else if (r < 60) return PUSH_FRONT;
     else if (r < 75) return POP_BACK;
     else if (r < 90) return POP_FRONT;
     else return ACCESS_INDEX;
 }
 
 void runDequeGauntlet(int operations) {
     Deque myDeque;
     vector<int> refVec;
 
     cout << "\n[Deque Gauntlet] Starting with " << operations << " operations..." << endl;
 
     for (int i = 0; i < operations; ++i) {
         Operation op = randomOperation();
         int value = rand() % 1000;
 
         switch (op) {
             case PUSH_BACK:
                 myDeque.push_back(value);
                 refVec.push_back(value);
                 break;
             case PUSH_FRONT:
                 myDeque.push_front(value);
                 refVec.insert(refVec.begin(), value);
                 break;
             case POP_BACK:
                 if (!refVec.empty()) {
                     myDeque.pop_back();
                     refVec.pop_back();
                 }
                 break;
             case POP_FRONT:
                 if (!refVec.empty()) {
                     myDeque.pop_front();
                     refVec.erase(refVec.begin());
                 }
                 break;
             case ACCESS_INDEX:
                 if (!refVec.empty()) {
                     int idx = rand() % refVec.size();
                     assert(myDeque[idx] == refVec[idx] && "Mismatch on operator[] access");
                 }
                 break;
         }
 
         assert(myDeque.size() == (int)refVec.size() && "Size mismatch between deque and vector");
 
         if (!refVec.empty()) {
             assert(myDeque.front() == refVec.front() && "Front value mismatch");
             assert(myDeque.back() == refVec.back() && "Back value mismatch");
         }
     }
 
     // Summary output
     cout << "[Deque Gauntlet] Test complete!" << endl;
     cout << "  Final size: " << myDeque.size() << endl;
 
     if (!myDeque.empty()) {
         cout << "  Front: " << myDeque.front() << endl;
         cout << "  Back : " << myDeque.back() << endl;
 
         cout << "  First 5 elements: ";
         for (int i = 0; i < min(5, myDeque.size()); ++i)
             cout << myDeque[i] << " ";
         cout << endl;
 
         cout << "  Last 5 elements : ";
         for (int i = max(0, myDeque.size() - 5); i < myDeque.size(); ++i)
             cout << myDeque[i] << " ";
         cout << endl;
 
         cout << "\n[Validation Samples from Deque vs std::vector]\n";
         for (int i = 0; i < 5; ++i) {
             int idx = rand() % refVec.size();
             int dequeVal = myDeque[idx];
             int vectorVal = refVec[idx];
             cout << "  Index " << idx << ": Deque = " << dequeVal
                  << ", std::vector = " << vectorVal
                  << (dequeVal == vectorVal ? " GO" : " NO-GO") << endl;
         }
     } else {
         cout << "  Deque is empty.\n";
     }
 
     cout << "[Deque Gauntlet] All tests passed successfully!" << endl;
 }
 
 int main() {
     cout << "===== Deque Gauntlet Test Driver =====" << endl;
 
     int operationCount;
     cout << "Enter number of operations to perform per run: ";
     cin >> operationCount;
 
     // Initial random seed
     int lastUsedSeed = static_cast<int>(time(0));
     srand(lastUsedSeed);
     cout << "Initial dry run of " << operationCount << " random operations with seed = " << lastUsedSeed << endl;
     runDequeGauntlet(operationCount);
 
     while (true) {
         cout << "\nChoose test mode:\n";
         cout << "  1. Reproduce last run (seed = " << lastUsedSeed << ")\n";
         cout << "  2. New random run\n";
         cout << "  3. Quit\n";
         cout << "Enter choice: ";
 
         int choice;
         cin >> choice;
 
         if (choice == 1) {
             cout << "Re-running with previous seed: " << lastUsedSeed << endl;
             srand(lastUsedSeed);
             runDequeGauntlet(operationCount);
         } else if (choice == 2) {
             lastUsedSeed = static_cast<int>(time(0));
             cout << "Running new random run with seed: " << lastUsedSeed << endl;
             srand(lastUsedSeed);
             runDequeGauntlet(operationCount);
         } else if (choice == 3) {
             cout << "Exiting. Goodbye!" << endl;
             break;
         } else {
             cout << "Invalid option. Try again.\n";
         }
     }
 
     return 0;
 }
 