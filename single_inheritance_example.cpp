// Build a simple class hierarchy using single inheritance in C++ with real world examples.
#include "iostream"
#include "string"

using namespace std;

// Base class
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

// Derived class
class Student : public Person {
    private:
        double gpa = 0.0;

    public:

        using Person::Person; // Inherit all constructors from Person

        // Default Constructor
        Student() : Person(), gpa(0.0) {}

        // Parameterized Constructor
        Student(string n, int a, double g) : Person(n, a), gpa(g) {} // iniliazer list

        // Destructor
        ~Student(){
                cout << "Student " << name << " is being destroyed." << endl;
        }

        // Getter for gpa
        double getGPA(){
            return this->gpa;
        }

        // Setter for gpa
        void setGPA(double g){
            this->gpa = g;
        }

        // Overloading the << operator for easy printing
        friend ostream& operator<<(ostream& os, const Student& s) {
            os << "Student Name: " << s.name << ", Age: " << s.age << ", GPA: " << s.gpa;
            return os;
        }
        
};

int main(){

    Student s1; // Default constructor

    Student s2("Ali", 22);

    Student s3("Alice", 20, 3.8); // Parameterized constructor  
    
    cout << s1 << endl; // Using overloaded << operator
    cout << s2 << endl; // Using overloaded << operator

    return 0;
}