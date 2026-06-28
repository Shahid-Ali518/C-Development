#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    Distance(int feet, float inches) : feet(feet), inches(inches)
    {}
    void showdist() // display distance
    {
        cout << feet << "\'- " << inches << '\"' << endl;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    Distance dist(12, 3.4);          // define a named Distance objec  
    dist.showdist();        //   with dot operator


    Distance *distptr;      // pointer to Distance
    distptr = new Distance(22, 3.1); // points to new Distance object

    distptr->showdist();    //   with -> operator

    // Explicitly freeing the heap memory
    delete distptr; 
    
    // Optional but good practice: set pointer to null so it doesn't point to garbage
    distptr = nullptr;

    
    cout << endl;


    return 0;
}