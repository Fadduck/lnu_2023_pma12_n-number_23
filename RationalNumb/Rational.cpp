#include <iostream>
#include <algorithm>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational()
        : numerator(0), denominator(1) {}

    Rational(int n, int d)
        : numerator(n), denominator(d) {}

    int WholePart() {
        int i = 0;
        if (numerator > denominator) {
            while ((numerator - denominator) >= 0) {
                i += 1;
                numerator -= denominator;
            }
        }
        return i;
    }

    int getNumerator() {
        return numerator;
    }

    int getDenominator() {
        return denominator;
    }

    int NOD(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        while (a % b != 0) {
            a = a % b;
            swap(a, b);
        }
        return b;
    }

    friend istream& operator>>(istream& is, Rational& product);
    friend ostream& operator<<(ostream& os, const Rational& product);
    friend Rational operator+(const Rational& rational1, const Rational& rational2);
    friend Rational operator*(const Rational& rational1, const Rational& rational2);
    friend Rational operator-(const Rational& rational1, const Rational& rational2);
    friend Rational operator/(const Rational& rational1, const Rational& rational2);
    friend bool operator>(const Rational& rational1, const Rational& rational2);
    friend bool operator<(const Rational& rational1, const Rational& rational2);
};

istream& operator>>(istream& is, Rational& p1) {
    cout << "Enter numerator: ";
    is >> p1.numerator;
    cout << "Enter denominator: ";
    is >> p1.denominator;

    return is;
}

ostream& operator<<(ostream& os, const Rational& p1) {
    os << p1.numerator << "/" << p1.denominator << endl;
    return os;
}

Rational operator+(const Rational& rational1, const Rational& rational2) {
    int num = (rational1.numerator * rational2.denominator) + (rational2.numerator * rational1.denominator);
    int denom = rational1.denominator * rational2.denominator;
    return Rational(num, denom);
}

Rational operator*(const Rational& rational1, const Rational& rational2) {
    int num = rational1.numerator * rational2.numerator;
    int denom = rational1.denominator * rational2.denominator;
    return Rational(num, denom);
}

Rational operator-(const Rational& rational1, const Rational& rational2) {
    int num = (rational1.numerator * rational2.denominator) - (rational2.numerator * rational1.denominator);
    int denom = rational1.denominator * rational2.denominator;
    return Rational(num, denom);
}

Rational operator/(const Rational& rational1, const Rational& rational2) {
    int num = rational1.numerator * rational2.denominator;
    int denom = rational1.denominator * rational2.numerator;
    return Rational(num, denom);
}

bool operator>(const Rational& rational1, const Rational& rational2) {
    int x = rational1.numerator / rational1.denominator;
    int y = rational2.numerator / rational2.denominator;
    return x > y;
}

bool operator<(const Rational& rational1, const Rational& rational2) {
    int x = rational1.numerator / rational1.denominator;
    int y = rational2.numerator / rational2.denominator;
    return x < y;
}

int main() {
    int numProducts;
    cout << "Enter number of Rational: ";
    cin >> numProducts;

    Rational r(4, 2);
    Rational* products = new Rational[numProducts];

    for (int i = 0; i < numProducts; i++) {
        cin >> products[i];
    }

    for (int i = 0; i < numProducts; i++) {
        cout << products[i];
    }

    for (int i = 0; i < numProducts; i++) {
        cout << "The whole part: " << products[i].WholePart() << endl;
        int num = (products[i].WholePart() * products[i].getDenominator()) - products[i].getNumerator();
        int den = products[i].getDenominator();
        Rational f(-num, den);
        cout << "Proper fraction: " << f;
    }

    Rational sum;
    Rational mult(1, 1);
    Rational div(1, 1);
    Rational sub(1, 1);

    for (int i = 0; i < numProducts; i++) {
        sum = sum + products[i];
        mult = mult * products[i];
        div = div / products[i];
        sub = sub - products[i];
    }

    sort(products, products + numProducts);

    cout << "Sorted Rationals: ";
    for (int i = 0; i < numProducts; i++) {
        cout << products[i] << " ";
    }
    cout << endl;

    int sum1 = sum.NOD(sum.getNumerator(), sum.getDenominator());
    if (sum.getDenominator() / sum1 == 1) {
        cout << "Sum: " << sum.getNumerator() / sum1 << endl;
    }
    else {
        cout << "Sum: " << sum.getNumerator() / sum1 << "/" << sum.getDenominator() / sum1 << endl;
    }

    cout << "Mult: " << mult.NOD(mult.getNumerator(), mult.getDenominator()) << endl;
    cout << "Div: " << div.NOD(div.getNumerator(), div.getDenominator()) << endl;
    cout << "Sub: " << sub.NOD(sub.getNumerator(), sub.getDenominator()) << endl;

    delete[] products;
    return 0;
}
