#include "Fraction.h"

Fraction::Fraction(int num, int den)
{
	numerator = num;
	if (den == 0)
	{
		denominator = 1;
	}
	else
	{
		denominator = den;
	}
}
