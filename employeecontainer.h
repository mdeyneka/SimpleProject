#ifndef EMPLOYEECONTAINER_H
#define EMPLOYEECONTAINER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "employeebase.h"
#include "employeefixedpay.h"
#include "employeehourlypay.h"

class EmployeeContainer
{
private:
    std::vector<std::shared_ptr<EmployeeBase>> employees;
public:
    EmployeeContainer(std::string filename);
    void deserialaze(std::string filename);
    void serialaze(std::string filename);
    void showAll();
    void sort();
private:
    std::shared_ptr<EmployeeBase> deserialazeLine(std::string line);
    std::string serializeLine(std::shared_ptr<EmployeeBase> employee);
};

#endif // EMPLOYEECONTAINER_H
