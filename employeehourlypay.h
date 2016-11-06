#ifndef EMPLOYEEHOURLYPAY_H
#define EMPLOYEEHOURLYPAY_H

#include "employeebase.h"

class EmployeeHourlyPay : public EmployeeBase
{
private:
    double employee_pay;
public:
    EmployeeHourlyPay(int id, std::string first_name,
                      std::string second_name, double pay):
                      EmployeeBase(id, first_name, second_name), employee_pay(pay){};
    virtual ~EmployeeHourlyPay(){};
    method_payment getMethodPayment() const {return method_payment::HourlyPay;};
    double getMonthlySalary() const;
};

#endif // EMPLOYEEHOURLYPAY_H
