#include "iostream"

using namespace std;

// Grand Parent class
class GrandParent
{

    int data;

public:
    GrandParent()
    {
        cout << "Grand Parent Constructor Called" << endl;
    }

    ~GrandParent()
    {
        cout << "Grand Parent Destructor Called " << endl;
    }

    void printMessage(){
        cout << "Message From Grand Parent" << endl;
    }
};

// Parent class A
class AParent : virtual public GrandParent
{

public:
    AParent()
    {
        cout << "Parent A Constructor Called" << endl;
    }

    ~AParent()
    {
        cout << "Parent A Destructor Called" << endl;
    }
};

// Parent class B
class BParent : virtual public GrandParent
{

public:
    BParent()
    { 
        cout << "Parent B Constructor Called " << endl;
    }

    ~BParent()
    {
        cout << "Parent B Destructor Called " << endl;
    }
};

// Parent class A
class GrandChild : public AParent, public BParent {

    public:
    GrandChild()
    {
        cout << "Grand Child Constructor Called" << endl;
    }

    ~GrandChild()
    {
        cout << "Grand Child Destructor Called" << endl;
    }

};

// main entry point
int main(){

    GrandChild child;

    child.printMessage();

    return 0;
}