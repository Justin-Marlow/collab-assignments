/** @file Employee.h
 *  @brief Declaration of the Employee class.
 *
 *  This class provides a basic structure for storing employee information and
 *  calculating pay based on hours worked and hourly rate.
 */

 #ifndef EMPLOYEE_H
 #define EMPLOYEE_H
 
 /**
  * @class Employee
  * @brief Represents an employee with basic information and functionality.
  *
  * The Employee class stores an employee's ID, years of service, hourly rate, 
  * and hours worked. It provides functions to print employee info, calculate pay,
  * and simulate an anniversary raise.
  */
 class Employee {
  private:
   int ID;               /**< Employee identification number */
   int years;            /**< Number of years employed */
 
  protected:
   double hourlyRate;    /**< Hourly pay rate */
   float hoursWorked;    /**< Total hours worked */
 
  public:
   /**
    * @brief Prints the employee's information.
    */
   virtual void print();
 
   /**
    * @brief Calculates the employee's total pay.
    * @return The total calculated pay (hourlyRate * hoursWorked).
    */
   virtual double calculatePay();
 
   /**
    * @brief Simulates an employee anniversary by increasing years and hourly rate.
    */
   void anniversary();
 
   /**
    * @brief Default constructor.
    *
    * Initializes all numeric members to -1.
    */
   Employee();
 
   /**
    * @brief Parameterized constructor.
    *
    * @param ID The employee's identification number.
    * @param years The number of years employed.
    * @param hourlyRate The employee's hourly pay rate.
    * @param hoursWorked The number of hours the employee has worked.
    */
   Employee(int ID, int years, double hourlyRate, float hoursWorked);
 };
 
 #endif // EMPLOYEE_H
 