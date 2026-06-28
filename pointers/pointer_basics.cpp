#include "iostream"

using namespace std;

int GLOABL_VAR = 100;
int GLOABL_MAX = 50;

int main()
{

    int var1 = 11;
    int var2 = 22;
    int var3 = 33;

    cout << &var1 << endl;
    cout << &var2 << endl;
    cout << &var3 << endl; // local variables stored in stack and addresses are in decsending order

    cout << &GLOABL_VAR << endl;
    cout << &GLOABL_MAX << endl; // global variables stored in heap memory and their addresses are acsending ordere

    int *ptr;
    ptr = &var1; // ptr points to var1 address

    cout << ptr << endl;
    cout << *ptr << endl; // prints content of var1

    ptr = &var2; // now ptr points to var2 address

    cout << ptr << endl;
    cout << *ptr << endl; // prints content of var2

    int v;
    int *ptrv;
    ptrv = &v;
    v = 3;

    *ptrv = 10;

    cout << *ptrv << endl;

    cout << "Pointer to void ===============" << endl;
    float flovar = 98.6;
    //int *ptrint = &flovar; // error 

    void* general_ptr; // pointer to point any data type
    int intvar = 10;
    float floatvar = 23.44;

    int* intptr;
    float* floatptr;
    void* voidptr;

    intptr = &intvar;
    floatptr = &floatvar;
    
    // pointer to void
    voidptr = &intvar;
    voidptr = &floatvar;

    cout << "Address: " << &intptr<< endl;
    cout << *intptr << endl;
    cout << *floatptr << endl;
    // cout << *voidptr << endl;
    // cout << *intptr << endl;

    int arr[] = {4, 5, 6};

    cout << "Array: " << *(arr + 6) << endl; // gives garbage value because array out of bound


    return 0;
}