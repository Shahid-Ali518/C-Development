#include "iostream"

using namespace std;

// A class
class A {

    private:
        int pridataA;
    protected:
        int prodataA;
    public:
        int pubdataA;

};

// B derived class
class B : public A {

    public:

        void func(){
            int a;
            //a = pridataA; // error not accessiable
            a = prodataA;
            a = pubdataA;
        }

};

// class C privatly derived 
class C : private A{

    public:
        void func(){
            int a;
            //a = pridataA; // error not accessiable
            a = prodataA;
            a = pubdataA;
        }
};


// main
int main(){

    // B class instance
    B objB;
    //objB.pridataA; // error not accessiable
    //objB.prodataA; // error not accessiable
    objB.pubdataA;  // OK (A is public to B)

    C objC;
    //objC.pridataA; // error not accessiable
    //objC.prodataA; // error not accessiable
    //objC.pubdataA; // error not accessiable (A is private to C)

    return 0;
}