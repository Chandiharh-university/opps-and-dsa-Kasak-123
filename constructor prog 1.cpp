#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle() : length(0), width(0) {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Rectangle(int l, int w) : length(l), width(w) {
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Rectangle(const Rectangle &rect) : length(rect.length), width(rect.width) {
        cout << "Copy constructor called" << endl;
    }

    // Method to calculate area
    int area() const {
        return length * width;
    }

    // Method to calculate perimeter
    int perimeter() const {
        return 2 * (length + width);
    }

    // Destructor
    ~Rectangle() {
        cout << "Destructor called for rectangle with length " 
             << length << " and width " << width << endl;
    }
};

int main() {
    Rectangle rect1; // Default constructor
    cout << "Area of rect1: " << rect1.area() << endl;

    Rectangle rect2(10, 5); // Parameterized constructor
    cout << "Area of rect2: " << rect2.area() << endl;

    Rectangle rect3(rect2); // Copy constructor
    cout << "Area of rect3: " << rect3.area() << endl;

    return 0;
}
