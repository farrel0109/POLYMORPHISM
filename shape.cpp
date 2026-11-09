
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;

    virtual ~Shape() {}
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing Rectangle ("
             << width << " x " << height << ")" << endl;
    }
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() const override {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    void draw() const override {
        cout << "Drawing Circle (r="
             << radius << ")" << endl;
    }
};

// Main Program
int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(2, 4));

    cout << fixed << setprecision(2);

    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "[" << i + 1 << "] ";
        shapes[i]->draw();

        cout << "    Area = "
             << shapes[i]->area() << endl;
    }

    // Memory cleanup
    for (size_t i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    return 0;
}
