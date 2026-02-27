#include <iostream>
using namespace std;

// Abstract base class
class Employee
{
public:
    virtual int calculateSalary() const = 0;

    virtual ~Employee() {}
};

// Derived class: OnlineCourse
class FullTimeEmployee : public Employee
{
private:
    int salary;

public:
    FullTimeEmployee(int s) : salary(s) 
    {}

    int calculateSalary() const override
    {
        return salary;
    }
};

// Derived class: OfflineCourse
class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    int hourlyRate;

public:
    PartTimeEmployee(int m, int h) : hoursWorked(m), hourlyRate(h) {}


    int calculateSalary() const override
    {

        return hoursWorked * hourlyRate;
    }
};

// Main function
int main()
{
    FullTimeEmployee fte(200000);
    PartTimeEmployee pte(40, 1000);

    cout << "Full Time Emplyee Salary: Rs." << fte.calculateSalary() << endl;
    cout << "Part Time Emplyee Salary: Rs." << pte.calculateSalary() << endl;

    return 0;
}
