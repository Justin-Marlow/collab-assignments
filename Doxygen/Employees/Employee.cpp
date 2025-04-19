/** @file Employee.cpp
 *  @brief Implementation file for the Employee class.
 */

 #include "Employee.h"
 #include <iostream>
 
 using namespace std;
 
 /// Default constructor
 Employee::Employee() {
   ID = years = hoursWorked = hourlyRate = -1;
 }
 
 /// Parameterized constructor (see Employee.h for full documentation)
 Employee::Employee(int ID, int years, double hourlyRate, float hoursWorked) {
   this->ID = ID;
   this->years = years;
   this->hourlyRate = hourlyRate;
   this->hoursWorked = hoursWorked;
 }
 
 /// Prints employee information to the console
 void Employee::print() {
   cout << "Printing information for employee " << ID << ":\n Years Employed: " << years
        << "\n Hourly Rate: " << hourlyRate << "\n Hours Worked: " << hoursWorked
        << endl;
 }
 
 /// Simulates an anniversary and applies a raise
 void Employee::anniversary() {
   years++;
   hourlyRate = hourlyRate + hourlyRate * .002;
   cout << "Congratulations to employee " << ID << " on " << years << " year(s) at company!"
        << endl;
 }
 
 /// Calculates the employee's total pay
 double Employee::calculatePay() {
   return hourlyRate * hoursWorked;
 }
 