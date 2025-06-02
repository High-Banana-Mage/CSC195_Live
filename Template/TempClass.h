#pragma once

template<typename T = int>
class TempClass
{
private:
	int x, y;
public:
	TempClass() : x{ 0 }, y{ 0 } {}
	TempClass(T x1, T y1) : x{ x1 }, y{ y1 } {}
};

template <typename T, int size>
class TempArray
{
private:
	T m_elements[size];

public:
	T operator [] (int index) { return m_elements[index]; }
};