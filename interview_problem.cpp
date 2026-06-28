#include "iostream"

using namespace std;

class A
{

    int *data;

public:
    A(int a)
    {
        data = new int(a);
    }

    ~A()
    {
        cout << "Destructor called. Deleting memory at address: " << data << endl;
        delete data;
    }

    void modify()
    {
        int x = 10; // Local Stack Variable
        data = &x;  // Changing 'data' pointer to point to 'x'
    }

    // 2. Modified "getPointer" method
    int getPointer()
    {
        int oldValue = *data; // Save the old value

        int x = 10; // Local Stack Variable
        data = &x;  // Changing 'data' pointer to point to 'x'

        return oldValue; // Return old value
    }

    void print() const {
        data ? 
            cout << "Address: " << data << ", Value: " << *data << endl
            :
            cout << "Pointer is null." << endl;
        
    }
};

int main()
{

    A a1(5);
    cout << "a1 initialized: "; a1.print();

    A a2 = a1; // The Trap Line!
    // cout << "a2 initialized (Copy): "; a2.print();

    // a2.modify();
    // cout << "After modifying a2 to 10:" << endl;
    // cout << "a1: "; a1.print();
    // cout << "a2: "; a2.print();

    return 0;
}