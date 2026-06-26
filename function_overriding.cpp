// Function Overriding in C++17

#include "iostream"


using namespace std;

// Base class
class Base {
    public:
        virtual void display() { // virtual function
            cout << "Display from Base class" << endl;
        }
};

// Derived class
class Derived : public Base {
    public:
        void display() { // overriding the virtual function
            cout << "Display from Derived class" << endl;
        }
};

int main() {
    Base* ptr;
    Derived d;
    ptr = &d;
    ptr->display(); // Calls Derived::display()
    return 0;
}