// build a multiple inheritance example with real world examples in C++.

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
class Manager : public Person, public Employee {
    private:
        int teamSize;

    public:

        using Person::Person; // Inherit all constructors from Person
        using Employee::Employee; // Inherit all constructors from Employee

        // Default Constructor
        Manager() : Person(), Employee(), teamSize(0) {}

        // Parameterized Constructor
        Manager(string n, int a, string c, double s, int t) : Person(n, a), Employee(c, s), teamSize(t) {}

        // Destructor
        ~Manager(){
                cout << "Manager " << name << " working at " << company << " is being destroyed." << endl;
        }

        // Getter for team size
        int getTeamSize(){
            return this->teamSize;
        }

        // Setter for team size
        void setTeamSize(int t){
            this->teamSize = t;
        }
        
};

int main(){

    Manager m1("Alice", 35, "TechCorp", 120000.0, 10); // Parameterized constructor

    cout << "Manager Name: " << m1.getName() << endl;
    cout << "Manager Age: " << m1.getAge() << endl;
    cout << "Manager Company: " << m1.getCompany() << endl;
    cout << "Manager Salary: $" << m1.getSalary() << endl;
    cout << "Manager Team Size: " << m1.getTeamSize() << endl;

    Person* p = new Manager("Bob", 40, "InnovateInc", 150000.0, 15); // Using base class pointer to derived class object
    cout << "Manager Name: " << p->getName() << endl;

    //Manager* m2 = new Person("Charlie", 45); // Using derived class pointer to base class object, // this will cause a compilation error because you cannot assign a base class object to a derived class pointer.

    Person P("Charlie", 45); // Using base class object

    // Person p = ("David", 50

    return 0;   
}