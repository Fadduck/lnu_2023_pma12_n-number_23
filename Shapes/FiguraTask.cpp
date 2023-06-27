#include <iostream>
using namespace std;

class _Shape {
public:
    virtual double get_Area() = 0;
    virtual double get_Perimeter() = 0;
    virtual void get_print() = 0;
};

class _Triangle : public _Shape {
private:
    double a, b, c;
public:
    _Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double get_Area() override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double get_Perimeter() override {
        return a + b + c;
    }
    void get_print() override {
        cout << "Triangle with sides " << a << ", " << b << ", " << c << endl;
        cout << "Area: " << get_Area() << endl;
        cout << "Perimeter: " << get_Perimeter() << endl;
    }
};

class _Rectangle : public _Shape {
private:
    double length, width;
public:
    _Rectangle(double length, double width) : length(length), width(width) {}
    double get_Area() override {
        return length * width;
    }
    double get_Perimeter() override {
        return 2 * (length + width);
    }
    void get_print() override {
        cout << "Rectangle with length " << length << " and width " << width << endl;
        cout << "Area: " << get_Area() << endl;
        cout << "Perimeter: " << get_Perimeter() << endl;
    }
};

class _Square : public _Shape {
private:
    double side;
public:
    _Square(double side) : side(side) {}
    double get_Area() override {
        return side * side;
    }
    double get_Perimeter() override {
        return 4 * side;
    }
    void get_print() override {
        cout << "Square with side " << side << endl;
        cout << "Area: " << get_Area() << endl;
        cout << "Perimeter: " << get_Perimeter() << endl;
    }
};

class _Circle : public _Shape {
private:
    double radius;
public:
    _Circle(double radius) : radius(radius) {}
    double get_Area() override {
        return 3.145 * radius * radius;
    }
    double get_Perimeter() override {
        return 2 * 3.145 * radius;
    }
    void get_print() override {
        cout << "Circle with radius " << radius << endl;
        cout << "Area: " << get_Area() << endl;
        cout << "Perimeter: " << get_Perimeter() << endl;
    }
};

class _Parallelogram : public _Shape {
private:
    double base, side, angle;
public:
    _Parallelogram(double base,  double side, double angle) : base(base), side(side), angle(angle) {}
    double get_Area() override {
        return base * side * sin(angle * 3.145 / 180);
    }
    double get_Perimeter() override {
        return 2 * (base + side);
    }
    void get_print() override {
        cout << "Parallelogram with base " << base << ", angle between those sides " << angle << ", and side " << side << endl;
        cout << "Area: " << get_Area() << endl;
        cout << "Perimeter: " << get_Perimeter() << endl;
    }
};

int main() {

    int _t_side1, _t_side2, _t_side3;
    cout << "Enter sides of triangle:" << endl;
    cin >> _t_side1;
    cin >> _t_side2;
    cin >> _t_side3;
    _Triangle t(_t_side1, _t_side2, _t_side3);
    t.get_print();

    int _r_side1, _r_side2;
    cout << "Enter sides of rectangle:" << endl;
    cin >> _r_side1;
    cin >> _r_side2;
    _Rectangle r(_r_side1, _r_side2);
    r.get_print();

    int _sq_side;
    cout << "Enter side of square" << endl;
    cin >> _sq_side;
    _Square s(_sq_side);
    s.get_print();

    int _r_circle;
    cout << "Enter radius of circle" << endl;
    cin >> _r_circle;
    _Circle c(_r_circle);
    c.get_print();

    int _p_side1, _p_side2, _p_angle;
    cout << "Enter sides of parallelogram and then angle between those sides(in degrees)" << endl;
    cin >> _p_side1;
    cin >> _p_side2;
    cin >> _p_angle;
    _Parallelogram p(_p_side1, _p_side2 , _p_angle);
    p.get_print();

    return 0;
};



