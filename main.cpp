#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int gcdValue = gcd(abs(numerator), abs(denominator));
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void convertToMixed() {
        if (numerator % denominator == 0) {
            cout << "Mixed form: " << numerator / denominator << endl;
        }
        else {
            cout << "Mixed form: " << numerator / denominator << " " << abs(numerator % denominator) << "/" << denominator << endl;
        }
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    if (f2.numerator == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    int num = f1.numerator * f2.denominator;
    int denom = f1.denominator * f2.numerator;
    return Fraction(num, denom);
}

void printFraction(const Fraction& f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

int main() {
    try {
        Fraction f1(3, 4);
        Fraction f2(2, 3);

        cout << "f1: ";
        printFraction(f1);
        cout << "f2: ";
        printFraction(f2);

        Fraction sum = f1 + f2;
        cout << "Sum: ";
        printFraction(sum);

        Fraction diff = f1 - f2;
        cout << "Difference: ";
        printFraction(diff);

        Fraction prod = f1 * f2;
        cout << "Product: ";
        printFraction(prod);

        Fraction quot = f1 / f2;
        cout << "Quotient: ";
        printFraction(quot);

        f1.convertToMixed();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
