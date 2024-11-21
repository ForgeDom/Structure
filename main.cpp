#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        if (denom == 0) {
            throw invalid_argument("Cannot divide by zero");
        }
        double r = (real * c.real + imag * c.imag) / denom;
        double i = (imag * c.real - real * c.imag) / denom;
        return Complex(r, i);
    }

    void print() const {
        if (imag < 0) {
            cout << real << " - " << -imag << "i" << endl;
        }
        else {
            cout << real << " + " << imag << "i" << endl;
        }
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double phase() const {
        return atan2(imag, real);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1: ";
    c1.print();

    cout << "c2: ";
    c2.print();

    Complex sum = c1 + c2;
    cout << "Sum: ";
    sum.print();

    Complex diff = c1 - c2;
    cout << "Difference: ";
    diff.print();

    Complex prod = c1 * c2;
    cout << "Product: ";
    prod.print();

    try {
        Complex quot = c1 / c2;
        cout << "Quotient: ";
        quot.print();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Magnitude of c1: " << c1.magnitude() << endl;
    cout << "Phase of c1: " << c1.phase() << endl;

    return 0;
}
