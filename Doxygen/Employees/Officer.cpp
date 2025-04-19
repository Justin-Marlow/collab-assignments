/** @file Officer.cpp
 *  @brief Implementation file for the Officer class.
 */

 #include "Officer.h"
 #include <iostream>
 
 using namespace std;
 
 /// Default constructor
 Officer::Officer() {
   evilness = 500;
 }
 
 /// Parameterized constructor (see Officer.h for documentation)
 Officer::Officer(int ID, int years, double hourlyRate, float hoursWorked, double evilness)
   : Employee(ID, years, hourlyRate, hoursWorked) {
   this->evilness = evilness;
 }
 
 /// Prints officer's details, including evilness
 void Officer::print() {
   Employee::print();
   cout << " Evilness: " << evilness << endl;
 }
 
 /// Calculates the officer's pay with an evilness-based bonus
 double Officer::calculatePay() {
   return (hourlyRate + evilness) * hoursWorked;
 }
 