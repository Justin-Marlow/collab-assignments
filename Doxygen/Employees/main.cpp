/** @mainpage Doxygen Testing
 *
 * @section intro_sec Introduction
 *
 * This project demonstrates the use of Doxygen to generate documentation
 * for a simple C++ class hierarchy involving employees, supervisors, and officers.
 *
 * @section structure_sec Class Structure
 * - Employee: Base class
 * - Supervisor: Derived class with bonus based on number of employees supervised
 * - Officer: Derived class with 'evilness' factor in pay calculation
 *
 * @section usage_sec How to Use
 * Open the "Classes" tab to explore individual class documentation,
 * or the "Files" tab to view the original source files and comments.
 *
 * @section doc_sec Generating Docs
 * Run `doxygen doxyConfig` in the project folder to regenerate this documentation.
 */


/** @file main.cpp
 *  @brief Entry point for testing the Employee, Supervisor, and Officer classes.
 *
 *  This file runs a series of tests to validate the functionality of the 
 *  Employee hierarchy, including constructors, pay calculation, and anniversary logic.
 */

 #include <iostream>
 #include "Employee.h"
 #include "Supervisor.h"
 #include "Officer.h"
 
 using namespace std;
 
 /// Runs a standard set of tests on an Employee or derived object
 void runEmployeeTests(Employee & e);
 
 int main() {
   // Test default Employee constructor
   Employee defaultE;
   cout << "Testing Employee default constructor:" << endl;
   runEmployeeTests(defaultE);
 
   cout << endl << endl;
 
   // Test parameterized Employee constructor
   Employee parameterizedE(1248, 2, 15.23, 3);
   cout << "Testing Employee parameterized constructor:" << endl;
   runEmployeeTests(parameterizedE);
 
   cout << endl << endl;
 
   // Test default Supervisor constructor
   Supervisor defaultS;
   cout << "Testing Supervisor default constructor:" << endl;
   runEmployeeTests(defaultS);
 
   cout << endl << endl;
 
   // Test parameterized Supervisor constructor
   Supervisor parameterizedS(422, 9, 55.44, 20, 52);
   cout << "Testing Supervisor parameterized constructor:" << endl;
   runEmployeeTests(parameterizedS);
 
   cout << endl << endl;
 
   // Test default Officer constructor
   Officer defaultO;
   cout << "Testing Officer default constructor:" << endl;
   runEmployeeTests(defaultO);
 
   cout << endl << endl;
 
   // Test parameterized Officer constructor
   Officer parameterizedO(2, 94, 10.859, 2, 9000.1);
   cout << "Testing Officer parameterized constructor:" << endl;
   runEmployeeTests(parameterizedO);
 
   return 0;
 }
 
 /// Executes print, calculatePay, and anniversary on a given Employee
 void runEmployeeTests(Employee &e) {
   cout << "Initial print():" << endl;
   e.print();
   cout << "Calculated Pay: " << e.calculatePay() << endl;
   cout << "Anniversary Test: ";
   e.anniversary();
   cout << "Final print():" << endl;
   e.print();
 }
 