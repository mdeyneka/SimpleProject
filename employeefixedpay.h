#ifndef EMPLOYEEFIXEDPAY_H
#define EMPLOYEEFIXEDPAY_H

#include "employeebase.h"

class EmployeeFixedPay :public EmployeeBase
{
private:
    double employee_pay;
public:
    EmployeeFixedPay(int id, std::string first_name,
                     std::string second_name, double pay):
                    EmployeeBase(id, first_name, second_name), employee_pay(pay){};
    virtual ~EmployeeFixedPay(){};
    method_payment getMethodPayment() const {return method_payment::FixedPay;};
    double getMonthlySalary() const;
};

#endif // EMPLOYEEFIXEDPAY_H
