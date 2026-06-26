#include "iostream"
#include "string"
#include "vector"


using namespace std;

// student class
class Student {

    private:
        string name;
        double gpa;

    public:

        // Default Constructor
        Student() {
            name = "Unknown";
            gpa = 0.0;
        }

        // Parameterized Constructor
        Student(string n, double g) {
            name = n;
            gpa = g;
        }

        // Destructor
        ~Student(){
                cout << "Student " << name << " is being destroyed." << endl;
        }

        // Getter for name
        string getName(){
            return this->name;
        }

        // Getter for gpa
        double getGPA(){
            return this->gpa;
        }

        // Setter for name
        void setName(string n){
            this->name = n;
        }

        // Setter for gpa
        void setGPA(double g){
            this->gpa = g;
        }

        // Overloading the << operator for easy printing
        friend ostream& operator<<(ostream& os, const Student& s) {
            os << "Student Name: " << s.name << ", GPA: " << s.gpa;
            return os;
        }
        
};


int main(){

    Student s1; // Default constructor

    // creare 5 students with different names and gpas
    Student s2("Alice", 3.8); // Parameterized constructor
    Student s3("Bob", 3.5);
    Student s4("Charlie", 3.9);
    Student s5("Diana", 3.7);

    cout << s2 << endl;

    // get higher gpa from the students
    vector<Student> students;
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);
    students.push_back(s4);
    students.push_back(s5);

    students.front().setName("Eve");

    Student highestStudent = students[0];
    for (int i = 1; i < students.size(); i++) {
        if (students[i].getGPA() > highestStudent.getGPA()) {
            highestStudent = students[i];
        }
    }

    cout << "Student with the highest GPA: " << highestStudent << endl;


    return 0;
}

