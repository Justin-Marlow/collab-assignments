/** @file Supervisor.cpp
 *  @brief Implementation file for the Supervisor class.
 */

 #include "Supervisor.h"
 #include <iostream>
 
 using namespace std;
 
 /// Default constructor
 Supervisor::Supervisor() {
   numSupervised = -1;
 }
 
 /// Parameterized constructor (see Supervisor.h for full documentation)
 Supervisor::Supervisor(int ID, int years, double hourlyRate, float hoursWorked, int numSupervised)
   : Employee(ID, years, hourlyRate, hoursWorked) {
   this->numSupervised = numSupervised;
 }
 
 /// Prints supervisor information including number supervised
 void Supervisor::print() {
   Employee::print();
   cout << " Number Supervised: " << numSupervised << endl;
 }
 
 /// Calculates supervisor's pay with a 1% bonus per supervised employee
 double Supervisor::calculatePay() {
   double val = Employee::calculatePay();
   val = val + val * (.01 * numSupervised);
   return val;
 }
 