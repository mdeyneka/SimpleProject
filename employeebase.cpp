#include "employeebase.h"

EmployeeBase::EmployeeBase(int id, std::string first_name, std::string second_name)
{
    this->employee_id = id;
    this->employee_first_name = first_name;
    this->employee_second_name = second_name;
}

void EmployeeBase::show() const
{
    if(getMethodPayment() == HourlyPay)
        std::cout << "EmployeeFixedPay: " << std::endl;
    else if (getMethodPayment() == FixedPay)
        std::cout << "EmployeeHourlyPay: " << std::endl;
    std::cout << "id: " << this->employee_id << std::endl;
    std::cout << "first name: " << this->employee_first_name << std::endl;
    std::cout << "second name: " << this->employee_second_name << std::endl;
    std::cout << "salary: " << this->getMonthlySalary() << std::endl;
    std::cout << std::endl;
}

EmployeeBase::~EmployeeBase()
{
    std::cout << "Employee with id: " << employee_id << " deleted." << std::endl;
}

