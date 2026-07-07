#include "iostream"

using namespace std;

// Base class
class base {

    public:
        virtual void show() = 0;  // now pure virtual method 

};

// derived1
class derived1 : public base {

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

    //base bad; // not allowed 
    base* arr[2]; // allowed

    derived1 der1;
    derived2 der2;


    // this is totally fine because pointer of base can point to the derived class
    arr[0] = &der1; 

    arr[0]->show(); // now it runs the exact method with respect to ptr content that is now derived1

    arr[1] = &der2; 

    arr[1]->show();


    return 0;
}