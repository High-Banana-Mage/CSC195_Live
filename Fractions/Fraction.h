#pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <type_traits>
using namespace std;

namespace mathlib {

    template<typename T>
    class Fraction {
        static_assert(is_integral_v<T>);

    private:
        T numerator_;
        T denominator_;

        T findGcd(T a, T b) const {
            if constexpr (is_signed_v<T>) {
                a = (a < 0) ? -a : a;
                b = (b < 0) ? -b : b;
            }

            // Euclidean algorithm
            while (b != T{ 0 }) {
                T temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        // Helper function to normalize sign (keep negative in numerator)
        void normalizeSign() {
            if constexpr (is_signed_v<T>) {
                if (denominator_ < 0) {
                    numerator_ = -numerator_;
                    denominator_ = -denominator_;
                }
            }
        }

    public:
        Fraction(const T& numerator = T{ 0 }, const T& denominator = T{ 1 })
            : numerator_(numerator), denominator_(denominator) {
            if (denominator_ == T{ 0 }) {
                throw invalid_argument("Denominator cannot be zero");
            }
            normalizeSign();
        }

        Fraction(const Fraction& other) = default;

        // Assignment operator
        Fraction& operator=(const Fraction& other) = default;

        ~Fraction() = default;

        const T& getNumerator() const { return numerator_; }
        const T& getDenominator() const { return denominator_; }

        Fraction& simplify() {
            T g = findGcd(numerator_, denominator_);
            if (g > T{ 1 }) {
                numerator_ /= g;
                denominator_ /= g;
            }
            return *this;
        }

        double toDouble() const {
            return static_cast<double>(numerator_) / static_cast<double>(denominator_);
        }

        // Arithmetic operators
        Fraction operator + (const Fraction& other) const {
            T newNum = numerator_ * other.denominator_ + other.numerator_ * denominator_;
            T newDen = denominator_ * other.denominator_;
            return Fraction(newNum, newDen).simplify();
        }

        Fraction operator - (const Fraction& other) const {
            T newNum = numerator_ * other.denominator_ - other.numerator_ * denominator_;
            T newDen = denominator_ * other.denominator_;
            return Fraction(newNum, newDen).simplify();
        }

        Fraction operator * (const Fraction& other) const {
            T newNum = numerator_ * other.numerator_;
            T newDen = denominator_ * other.denominator_;
            return Fraction(newNum, newDen).simplify();
        }

        Fraction operator / (const Fraction& other) const {
            if (other.numerator_ == T{ 0 }) {
                throw invalid_argument("Division by zero fraction");
            }
            T newNum = numerator_ * other.denominator_;
            T newDen = denominator_ * other.numerator_;
            return Fraction(newNum, newDen).simplify();
        }

        // Comparison operators
        bool operator == (const Fraction& other) const {
            return numerator_ * other.denominator_ == other.numerator_ * denominator_;
        }

        bool operator != (const Fraction& other) const {
            return !(*this == other);
        }

        bool operator < (const Fraction& other) const {
            if constexpr (is_signed_v<T>) {
                T left = numerator_ * other.denominator_;
                T right = other.numerator_ * denominator_;

                if ((denominator_ > 0 && other.denominator_ > 0) ||
                    (denominator_ < 0 && other.denominator_ < 0)) {
                    return left < right;
                }
                else {
                    return left > right;
                }
            }
            else {
                return numerator_ * other.denominator_ < other.numerator_ * denominator_;
            }
        }

        bool operator > (const Fraction& other) const {
            return other < *this;
        }

        bool operator <= (const Fraction& other) const {
            return !(other < *this);
        }

        bool operator >= (const Fraction& other) const {
            return !(*this < other);
        }

        // Stream operators
        friend ostream& operator<<(ostream& os, const Fraction& frac) {
            if (frac.denominator_ == T{ 1 }) {
                os << frac.numerator_;
            }
            else {
                os << frac.numerator_ << "/" << frac.denominator_;
            }
            return os;
        }

        friend istream& operator>>(istream& is, Fraction& frac) {
            T num, den = T{ 1 };
            char slash;

            is >> num;
            if (is.peek() == '/') {
                is >> slash >> den;
                if (den == T{ 0 }) {
                    is.setstate(ios::failbit);
                    return is;
                }
            }

            if (is.good()) {
                frac = Fraction(num, den);
            }
            return is;
        }
    };

}