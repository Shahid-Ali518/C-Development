#include "iostream"
#include "cstring"

using namespace std;

// Custom string class
class String
{

private:
    char* str;

public:
    String(char* s){
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String(){
        cout << "Destructor is called for address: " << (void*)str << endl;
        delete[] str;
        str = nullptr; // Now it points to nothing, instead of a ghost address
    }

    void display() const {

        cout << str << endl;
    }


};

int main()
{

    String s("This is my new Program");

    s.display();

    String s1 = s;

    return 0;
}