/** @file Officer.h
 *  @brief Declaration of the Officer class.
 *
 *  The Officer class inherits from Employee and introduces an additional
 *  attribute: evilness, which influences the pay calculation.
 */

 #ifndef OFFICER_H
 #define OFFICER_H
 
 #include "Employee.h"
 
 /**
  * @class Officer
  * @brief Derived class from Employee that adds an "evilness" factor to pay.
  *
  * The Officer class extends the Employee class by adding a custom
  * evilness multiplier, which affects the total pay calculation.
  */
 class Officer : public Employee {
  private:
   double evilness; /**< Evilness factor added to hourly rate for pay calculation */
 
  public:
   /**
    * @brief Prints the officer's full details including evilness.
    */
   void print();
 
   /**
    * @brief Calculates the officer's pay with evilness considered.
    * 
    * @return The officer's total pay.
    */
   double calculatePay();
 
   /**
    * @brief Default constructor.
    *
    * Initializes evilness to a default value.
    */
   Officer();
 
   /**
    * @brief Parameterized constructor.
    *
    * @param ID Employee ID.
    * @param years Number of years worked.
    * @param hourlyRate Hourly wage.
    * @param hoursWorked Total hours worked.
    * @param evilness Bonus evilness factor for pay.
    */
   Officer(int ID, int years, double hourlyRate, float hoursWorked, double evilness);
 };
 
 #endif // OFFICER_H
 