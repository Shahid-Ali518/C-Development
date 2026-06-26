#include "iostream"

using namespace std;

// Function overloading example
// Function to add two integers

int add(int a, int b){
    return a + b;
}

// double add(int a, int b){ // function can't overload just by changing return type
//     return a + b;
// }

// Function to add three integers
double add(int a, int b, int c){
    return a + b + c;
}

int main() {

    int x = 5, y = 10, z = 15;

    cout << "Sum of two integers: " << add(x, y) << endl;
    cout << "Sum of three integers: " << add(x, y, z) << endl;

    return 0;
}

