#include "iostream"

using namespace std;

// Base class
class base {

    public:
        virtual void show()  // now virtual method
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

    ptr->show(); // now it runs the exact method with respect to ptr content that is now derived1

    ptr = &der2; // ptr points to the derived2

    ptr->show();


    return 0;
}