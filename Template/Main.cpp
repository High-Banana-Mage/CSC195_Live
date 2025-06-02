#include <iostream>
#include "TempClass.h"
using namespace std;

namespace awe
{
	/*
	int max(int i1, int i2)
	{
		return (i1 > i2) ? i1 : i2;
	}

	float max(float f1, float f2)
	{
		return (f1 > f2) ? f1 : f2;
	}
	*/

	template<typename T, typename D>
	T max(T i1, D i2)
	{
		return (i1 > i2) ? i1 : i2;
	}


}

int main()
{

	cout << awe::max(2.3f, 5.6f) << endl;
	cout << awe::max(2, 5) << endl;
	cout << awe::max(7, 5.6f) << endl;

	TempClass<> t1(5, 7);
	TempClass<float> t2(2.3f, 3.6f);

	TempArray<string, 5> tA1;

	tA1[2] = "Hi";

}