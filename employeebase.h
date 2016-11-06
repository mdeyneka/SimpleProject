#ifndef EMPLOYEEBASE_H
#define EMPLOYEEBASE_H

#include <iostream>
#include <string>

class EmployeeBase
{
public:
  enum method_payment {
      HourlyPay = 0,
      FixedPay = 1
  };
private:
    int employee_id;
    std::string employee_first_name;
    std::string employee_second_name;
public:
    EmployeeBase(int id, std::string first_name, std::string second_name);
    virtual ~EmployeeBase();
    virtual double getMonthlySalary() const = 0;
    virtual method_payment getMethodPayment() const = 0;
    int getId() const { return this->employee_id;};
    std::string getFirstName() const { return this->employee_first_name;};
    std::string getSecondName() const { return this->employee_second_name;};
    void show() const;
};

#endif // EMPLOYEEBASE_H
