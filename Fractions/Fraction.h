#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

namespace mathlib {

    template<typename T>
    class Fraction {
    private:
        T num, den;

        //I used claude to help me find a formula to get the gcd
        T gcd(T a, T b) {
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            while (b != 0) {
                T temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

    public:
        Fraction(T numerator = 0, T denominator = 1) : num(numerator), den(denominator) {
            if (den == 0) {
                throw invalid_argument("Denominator cannot be zero");
            }
        }

        T getNumerator() const { return num; }
        T getDenominator() const { return den; }

        Fraction& simplify() {
            T g = gcd(num, den);
            if (g > 1) {
                num /= g;
                den /= g;
            }

            if (den < 0) {
                num = -num;
                den = -den;
            }
            return *this;
        }

        double toDouble() const {
            return static_cast<double>(num) / static_cast<double>(den);
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

        bool operator>(const Fraction& other) const {
            return other < *this;
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

        friend istream& operator>>(istream& is, Fraction& f) {
            T numerator, denominator = 1;
            char slash;
            //I used Claude to help me extract the fraction
            is >> numerator;
            if (is.peek() == '/') {
                is >> slash >> denominator;
                if (denominator == 0) {
                    is.setstate(ios::failbit);
                    return is;
                }
            }

            if (is.good()) {
                f = Fraction(numerator, denominator);
            }
            return is;
        }
    };

}