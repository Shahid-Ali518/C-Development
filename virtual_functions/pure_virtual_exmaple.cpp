#include "iostream"
#include "string"

using namespace std;

// Base class
class Person {

    protected:
        string name;

    public:

        Person(string name) : name(name)
        {}

        // Add a virtual destructor so derived classes clean up completely
        virtual ~Person() {
            // Even an empty virtual destructor forces C++ to look up the 
            // derived class destructors at runtime.
        }

        void showName() const 
        {
            cout << "Name is: " << name << " ";
        }


        virtual void showData() = 0;  // now pure virtual method 
        virtual bool isOutstanding() = 0;  // now pure virtual method 

};

// derived1
class Student : public Person {

    private:
        float gpa;

     public:

        Student(string name, float gpa) : gpa(gpa), Person(name)
        {}

        void showData() override
        {
            Person::showName();
            isOutstanding() ? cout << "and Person is outstanding" << endl
                        : 
                            cout << "and Person is ordinary" << endl;
 
        }

        bool isOutstanding() override
        {
            return gpa >= 3.5 ? true : false;
        }

};

// derived2
class Professor : public Person {

    private:
        int numOfPub;

     public:

        Professor(string name, int num) : numOfPub(num), Person(name)
        {}

        void showData() override
        {
            Person::showName();
            isOutstanding() ? cout << "and Person is outstanding" << endl
                        : 
                            cout << "and Person is ordinary" << endl;
        }
        

        bool isOutstanding() override
        {
            return numOfPub >= 50 ? true : false;
        }

};


int main () {

    Person* persons[10];

    // pointers to point student type
    persons[0] = new Student("Shahid", 3.5);
    persons[1] = new Student("Raza", 3.3);
    persons[2] = new Student("Sana", 3.9);
    persons[3] = new Student("Saqib", 3.3);
    persons[4] = new Student("Eman", 3.7);


    // pointers to point professor type
    persons[5] = new Professor("Asim Rasool", 55);
    persons[6] = new Professor("Arifa Mirza", 44);
    persons[7] = new Professor("Adeel Nisar", 57);
    persons[8] = new Professor("Abdul Mateen", 55);
    persons[9] = new Professor("Arif Butt", 35);



    for(int i = 0; i<10; i++)
        persons[i]->showData();



    // deleting the heap memory
    for(int i = 0; i < 10; i++)
        delete persons[i];


    return 0;
}