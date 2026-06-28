#include "iostream"

using namespace std;

void centimize(double*); // ptototype
void modify(int*);
void centimizeArray(double*);

int main()
{
    double var = 10.0;

    cout << "var: " << var << endl;

    centimize(&var);

    cout << "var: " << var << endl;

    int* intptr = new int(5);

    modify(intptr);

    *intptr *= 2;

    cout << intptr << endl;
    cout << *intptr << endl;

    double array[] = {10.0, 12.4, 15.2, 16.6, 18.9};

    centimizeArray(array); // because array name is address of first element itself

    for(double v: array)
        cout << v << " " ;

    cout << endl;


    return 0;
}


void centimize(double* ptrd){
    *ptrd *= 2.54;
}

void modify(int* p){
    int a = 10;
    p = &a;
}

void centimizeArray(double* ptrd){


    for(int j = 0; j <5; j++)
        *ptrd++ *= 2.54; // ptrd moves to next locations due to ++    
}