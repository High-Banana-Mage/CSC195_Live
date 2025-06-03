#include "Fraction.h"
#include <iostream>


using namespace std;
using namespace mathlib;

int main()
{

    Fraction<int> fraction1{ 15, 5 };
    cout << fraction1 << endl;

    Fraction<int> fraction2{ 15, 6 };
    fraction2.simplify();
    cout << fraction2 << endl;

    cout << fraction1 << " == " << fraction2 << " result: " << (fraction1 == fraction2) << endl;
    cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << endl;

    cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << endl;
    cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << endl;

    Fraction<int> fraction3;
    cout << "input fraction (numerator/denominator): \n";
    cin >> fraction3;
    cout << fraction3 << endl;
    cout << fraction3.toDouble() << endl;

    return 0;
}