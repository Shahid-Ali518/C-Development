#include "iostream"

using namespace std;

// Base class
class base {

    public:
        void show() 
        {
            cout << "base" << endl;
        }

};

// derived1
class derived1 :public base {

     public:
        void show() 
        {
            cout << "derived1" << endl;
        }

};

// derived2
class derived2 : public base {

     public:
        void show() 
        {
            cout << "derived2" << endl;
        }

};


int main () {


    derived1 der1;
    derived2 der2;

    base* ptr;

    // this is totally fine because pointer of base can point to the derived class
    ptr = &der1; // ptr points to the derived1 

    ptr->show();

    ptr = &der2; // ptr points to the derived2

    ptr->show(); // everytime it calls base method due to static/early binding.


    return 0;
}