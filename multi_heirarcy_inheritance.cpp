// build a multi heirarchy inheritance example with real world examples in C++.

#include "iostream"
#include "string"

using namespace std;

// Base class 1
class Person {
    protected:
        string name;
        int age;

    public:
        // Default Constructor
        Person() {
            name = "Unknown";
            age = 0;
        }

        // Parameterized Constructor
        Person(string n, int a) {
            name = n;
            age = a;
        }

        // Destructor
        ~Person(){
                cout << "Person " << name << " is being destroyed." << endl;
        }

        // Getter for name
        string getName(){
            return this->name;
        }

        // Getter for age
        int getAge(){
            return this->age;
        }

        // Setter for name
        void setName(string n){
            this->name = n;
        }

        // Setter for age
        void setAge(int a){
            this->age = a;
        }
};

// Base class 2
class Employee {
    protected:
        string company;
        double salary;

    public:
        // Default Constructor
        Employee() {
            company = "Unknown";
            salary = 0.0;
        }

        // Parameterized Constructor
        Employee(string c, double s) {
            company = c;
            salary = s;
        }

        // Destructor
        ~Employee(){
                cout << "Employee working at " << company << " is being destroyed." << endl;
        }

        // Getter for company
        string getCompany(){
            return this->company;
        }

        // Getter for salary
        double getSalary(){
            return this->salary;
        }

        // Setter for company
        void setCompany(string c){
            this->company = c;
        }

        // Setter for salary
        void setSalary(double s){
            this->salary = s;
        }
};


// Derived class
class StudentEmployee : public Person, public Employee {
    private:
        string studentID;

    public:
        // Default Constructor
        StudentEmployee() : Person(), Employee() {
            studentID = "Unknown";
        }

        // Parameterized Constructor
        StudentEmployee(string n, int a, string c, double s, string id) 
            : Person(n, a), Employee(c, s) {
            studentID = id;
        }

        // Destructor
        ~StudentEmployee(){
                cout << "StudentEmployee with ID " << studentID << " is being destroyed." << endl;
        }

        // Getter for studentID
        string getStudentID(){
            return this->studentID;
        }

        // Setter for studentID
        void setStudentID(string id){
            this->studentID = id;
        }
};

// Main function to demonstrate multi-hierarchy inheritance
int main() {
    StudentEmployee se("Alice", 20, "TechCorp", 1500.0, "S12345");

    cout << "Name: " << se.getName() << endl;
    cout << "Age: " << se.getAge() << endl;
    cout << "Company: " << se.getCompany() << endl;
    cout << "Salary: $" << se.getSalary() << endl;
    cout << "Student ID: " << se.getStudentID() << endl;

    return 0;
}