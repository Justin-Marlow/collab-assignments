/** @file Supervisor.h
 *  @brief Declaration of the Supervisor class.
 *
 *  The Supervisor class extends the Employee class by introducing
 *  a bonus based on the number of employees supervised.
 */

 #ifndef SUPERVISOR_H
 #define SUPERVISOR_H
 
 #include "Employee.h"
 
 /**
  * @class Supervisor
  * @brief Represents a supervisor who manages other employees.
  *
  * Inherits from the Employee class and includes a supervision bonus in pay
  * calculations based on the number of employees supervised.
  */
 class Supervisor : public Employee {
  private:
   int numSupervised; /**< Number of employees supervised */
 
  public:
   /**
    * @brief Prints the supervisor's full details including number supervised.
    */
   void print();
 
   /**
    * @brief Calculates the supervisor's total pay.
    *
    * Pay includes a 1% bonus per supervised employee.
    * 
    * @return The total calculated pay.
    */
   double calculatePay();
 
   /**
    * @brief Default constructor.
    *
    * Initializes numSupervised to -1.
    */
   Supervisor();
 
   /**
    * @brief Parameterized constructor.
    *
    * @param ID Supervisor's employee ID.
    * @param years Years of employment.
    * @param hourlyRate Supervisor's hourly wage.
    * @param hoursWorked Total hours worked.
    * @param numSupervised Number of employees supervised.
    */
   Supervisor(int ID, int years, double hourlyRate, float hoursWorked, int numSupervised);
 };
 
 #endif // SUPERVISOR_H
 