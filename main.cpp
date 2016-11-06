#include <iostream>
#include <string>
#include "employeebase.h"
#include "employeehourlypay.h"
#include "employeefixedpay.h"
#include "employeecontainer.h"

int main()
{
    std::string in;
    EmployeeContainer e_container("employees.txt");
    std::cout << "Print:\n\"4\" for quit" << std::endl;
    std::cout << "\"1\" for show all employees" << std::endl;
    std::cout << "\"2\" for sort employees by monthly salary" << std::endl;
    std::cout << "\"3\" for write employees to file" << std::endl;
    do{
         std::cin >> in;
         switch (std::stoi(in)) {
           case 1:
             e_container.showAll();
             break;
           case 2:
             e_container.sort();
             break;
           case 3:
             e_container.serialaze("employee_test.txt");
             break;
           default:
             std::cout << "Unknown command" << std::endl;
             break;
           }
         std::cout << "-------------------------------" << std::endl;
    }while(in != "4");
    return 0;
}
