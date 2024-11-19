#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int employee_id;
    double salary;

    Employee(string name, int employee_id, double salary)
    {
        this->name = name;
        this->employee_id = employee_id;
        this->salary = salary;
    }

    virtual double calculate_salary()
    {
        return salary;
    }

    virtual void displayInfo()
    {
        cout << "Employee " << name << " (ID: " << employee_id << ") earns Rs. " << calculate_salary() << " per month.\n";
    }

    virtual ~Employee() {}
};

class Professor : public Employee
{
public:
    double bonus;
    string dept;

    Professor(string name, int employee_id, double salary, string dept)
        : Employee(name, employee_id, salary), dept(dept) {}

    double calculate_salary() override
    {
        bonus = salary * 0.10;
        return bonus + salary;
    }

    void displayInfo() override
    {
        cout << "Professor " << name << " (ID: " << employee_id << ")"
             << " from " << dept << " department earns Rs. "
             << calculate_salary() << " per month.\n";
    }
};

class AdminStaff : public Employee
{
public:
    string position;
    double bonus;

    AdminStaff(string name, int employee_id, double salary, string position)
        : Employee(name, employee_id, salary), position(position) {}

    double calculate_salary() override
    {
        bonus = salary * 0.5;
        return bonus + salary;
    }

    void displayInfo() override
    {
        cout << "Admin Staff " << name << " (ID: " << employee_id << ")"
             << " holding " << position << " position earns Rs. "
             << calculate_salary() << " per month.\n";
    }
};

class Janitor : public Employee
{
public:
    int hoursWorked;

    Janitor(string name, int employee_id, int hoursWorked)
        : Employee(name, employee_id, 0), hoursWorked(hoursWorked) {}

    double calculate_salary() override
    {
        double wagePerHour = 500;
        return hoursWorked * wagePerHour;
    }

    void displayInfo() override
    {
        cout << "Janitor " << name << " (ID: " << employee_id << ")"
             << " worked " << hoursWorked << " hours and earns Rs. "
             << calculate_salary() << " per month.\n";
    }
};

int main()
{
    Professor prof("Aarushi", 101, 50000, "Computer Science");
    AdminStaff admin("Hemlata", 102, 30000, "HR Manager");
    Janitor janitor("Anushka", 103, 160);

    prof.displayInfo();
    admin.displayInfo();
    janitor.displayInfo();

    return 0;
}
