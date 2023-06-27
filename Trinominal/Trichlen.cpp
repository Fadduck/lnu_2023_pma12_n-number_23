#include <iostream>
#include <cmath>
using namespace std;


template <typename T>
class Trinominal
{
protected:
    T a;
    T b;
    T c;
public:
    Trinominal() : a(T()), b(T()), c(T()) {};
    Trinominal(T a, T b, T c) : a(a), b(b), c(c) {};
    T Discriminant()
    {
        return (b * b - 4 * a * c);
    }
    void Roots()
    {
        T discriminant = Discriminant();
        if (discriminant > T())
        {
            T x1 = (-b + sqrt(discriminant)) / (2 * a);
            T x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "x1= " << x1 << " , "
                << "x2= " << x2 << endl;
        }
        else if (discriminant == T())
        {
            T x = -b / (2 * a);
            cout << "x= " << x << endl;
        }
        else
        {
            cout << "No roots" << endl;
        }
    }

    void Scalar(T scalar)
    {
        a *= scalar;
        b *= scalar;
        c *= scalar;
        cout << "After scalaring: " << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
    }

    Trinominal<T> operator+(Trinominal < T>& other)
    {
        Trinominal<T> result(a + other.a, b + other.b, c + other.c);
        return result;
    }

    Trinominal<T> operator-(Trinominal<T>& other)
    {
        Trinominal<T> result(a - other.a, b - other.b, c - other.c);
        return result;
    }

    friend istream& operator>>(istream& is, Trinominal<T>& other)
    {
        cout << "Enter a: ";
        cin.ignore();
        is >> other.a;
        cout << "Enter b: ";
        cin.ignore();
        is >> other.b;
        cout << "Enter c: ";
        cin.ignore();
        is >> other.c;
        return is;
    }

    friend ostream& operator<<(ostream& os, Trinominal<T>& other)
    {
        os << other.a << "x^2 ";
        if (other.b >= T())
        {
            os << " + " << other.b << "x";
        }
        else
        {
            os << "- " << -other.b << "x ";
        }
        if (other.c >= T())
        {
            os << "+ " << other.c;
        }
        else
        {
            os << "- " << -other.c;
        }
        os << endl;
        os << "Discriminant: " << other.Discriminant() << endl;
        return os;
    }
};

template <typename R>
class ReducedTrinominal : public Trinominal<R>
{
public:
    ReducedTrinominal() : Trinominal<R>() {};
    ReducedTrinominal(R a, R b, R c) : Trinominal<R>(a, b, c) {};

    friend istream& operator>>(istream& is, ReducedTrinominal<R>& other)
    {
        cout << "Enter b: ";
        is >> other.b;
        cout << "Enter c: ";
        is >> other.c;
        return is;
    }

    friend ostream& operator<<(ostream& os, ReducedTrinominal<R>& other)
    {
        os << "x^2 ";
        if (other.b >= R())
        {
            os << " + " << other.b << "x";
        }
        else
        {
            os << "- " << -other.b << "x ";
        }
        if (other.c >= R())
        {
            os << "+ " << other.c;
        }
        else
        {
            os << "- " << -other.c;
        }
        os << endl;
        os << "Discriminant: " << other.Discriminant() << endl;
        return os;
    }
};

int main() {
    Trinominal<double>t1, t2;
    ReducedTrinominal<double>t3;
    double scalar;

    cout << "Enter details of the first trinomial:" << endl;
    cin.ignore();
    cin >> t1;

    cout << "Enter details of the second trinomial:" << endl;
    cin.ignore();
    cin >> t2;
    cout << "Enter details of the third trinomial:" << endl;
    cin.ignore();
    cin >> t3;

    cout << "Enter scalar value: ";
    cin >> scalar;

    cout << "First trinomial:" << endl;
    cout << t1;

    cout << "Second trinomial:" << endl;
    cout << t2;
    cout << "Third trinomial:" << endl;
    cout << t3;

    Trinominal<double> sum = t1 + t2;
    cout << "Sum of trinomials:" << endl;
    cout << sum;

    Trinominal<double> difference = t1 - t2;
    cout << "Difference of trinomials:" << endl;
    cout << difference;

    t1.Scalar(scalar);

    cout << "Roots of the first trinomial:" << endl;
    t1.Roots();

    cout << "Roots of the second trinomial:" << endl;
    t2.Roots();

}
