// pointers examples

#include "iostream"

using namespace std;

int main() {

    int a = 10;
    int* ptr = &a; // pointer to an integer

    cout << "Value of a: " << a << endl; // 10
    cout << "Address of a: " << &a << endl; // address of a
    cout << "Value of ptr: " << ptr << endl; // address of a
    cout << "Value pointed to by ptr: " << *ptr << endl; // 10

    *ptr = 20; // changing the value of a through the pointer

    cout << "New value of a: " << a << endl; // 20

    return 0;
}