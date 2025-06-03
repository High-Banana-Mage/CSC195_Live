#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Fraction {
private:
    int num, den;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(int numerator = 0, int denominator = 1) : num(numerator), den(denominator) {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    int getNumerator() const { return num; }
    int getDenominator() const { return den; }

    double toDouble() const {
        return static_cast<double>(num) / den;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            throw invalid_argument("Division by zero");
        }
        return Fraction(num * other.den, den * other.num);
    }

    bool operator==(const Fraction& other) const {
        return num * other.den == other.num * den;
    }

    bool operator<(const Fraction& other) const {
        return num * other.den < other.num * den;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.den == 1) {
            os << f.num;
        }
        else {
            os << f.num << "/" << f.den;
        }
        return os;
    }
};