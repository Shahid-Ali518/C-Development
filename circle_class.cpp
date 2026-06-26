#include "iostream"
#include "string"

using namespace std;

// cicle class
class Circle {

    private:
        double radius;

    public:

        // Default Constructor
        Circle() {
            radius = 1.0;
        }

        // Parameterized Constructor
        Circle(double r) {
            radius = r;
        }

        // Destructor
        ~Circle(){
                cout << "Circle with radius " << radius << " is being destroyed." << endl;
        }

        // Getter 
        double getRadius(){
            return this->radius;
        }

        // Setter 
        void setRadius(double r){
            this->radius = r;
        }

        // Method to calculate area
        double area(){
            return 3.14159 * radius * radius;
        }

        // Method to calculate circumference
        double circumference(){
            return 2 * 3.14159 * radius;
        }
        
};

int main(){

    Circle c1; // Default constructor
    Circle c2(5.0); // Parameterized constructor  
    
    cout << "Circle 1 - Radius: " << c1.getRadius() << ", Area: " << c1.area() << ", Circumference: " << c1.circumference() << endl;
    cout << "Circle 2 - Radius: " << c2.getRadius() << ", Area: " << c2.area() << ", Circumference: " << c2.circumference() << endl;


    return 0;
}





