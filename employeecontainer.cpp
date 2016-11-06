#include "employeecontainer.h"

EmployeeContainer::EmployeeContainer(std::string filename)
{
  deserialaze(filename);
}

void EmployeeContainer::showAll()
{
    for(auto it = employees.begin(); it != employees.end(); ++it)
    {
        (*it)->show();
    }
}

void EmployeeContainer::sort()
{
    std::sort(employees.begin(),
              employees.end(),
              [](const std::shared_ptr<EmployeeBase> x, const std::shared_ptr<EmployeeBase> y)
              {
                  return (x->getMonthlySalary() < y->getMonthlySalary());
              });
}

std::shared_ptr<EmployeeBase> EmployeeContainer::deserialazeLine(std::string line)
{
    std::vector<std::string> elems;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) {
       elems.push_back(item);
    }
    std::shared_ptr<EmployeeBase> employee;
    if(std::stoi(elems.at(3)) == 0)
    {
        employee = std::shared_ptr<EmployeeBase>(new EmployeeHourlyPay(std::stoi(elems[0]), elems[1], elems[2], std::stof(elems[4])));
    } else if (std::stoi(elems.at(3)) == 1) {
        employee = std::shared_ptr<EmployeeBase>(new EmployeeFixedPay(std::stoi(elems[0]), elems[1], elems[2], std::stof(elems[4])));
    }
    return std::move(employee);
}

std::string EmployeeContainer::serializeLine(std::shared_ptr<EmployeeBase> employee)
{
    std::stringstream stream;
    stream << std::to_string(employee->getId()) << ","
           << employee->getFirstName() << ","
           << employee->getSecondName()
           << "," << std::to_string(EmployeeBase::FixedPay) << ","
           << employee->getMonthlySalary();
    return  stream.str();
}

void EmployeeContainer::deserialaze(std::string filename)
{
    std::string line;
    std::ifstream file(filename);
    if(file.is_open())
    {
      while(getline(file,line))
      {
          employees.push_back(deserialazeLine(line));
      }
      file.close();
    }
    else std::cout << "Unable to open file " << filename;
}

void EmployeeContainer::serialaze(std::string filename)
{
    std::ofstream file(filename);
    if(file.is_open())
    {
        for(auto it = employees.begin(); it != employees.end(); ++it)
        {
            file << this->serializeLine(*it) << "\n";
        }
        file.close();
    }
    else std::cout << "Unable to open file";
}

