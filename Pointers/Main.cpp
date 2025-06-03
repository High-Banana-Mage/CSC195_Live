#define _CRT  DBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;

template<typename T>
class smart_ptr
{
public:
	smart_ptr(T* ptr = nullptr) : _ptr{ ptr } {}
	smart_ptr(const smart_ptr&) = delete;
	smart_ptr& operator = (const smart_ptr&) = delete;

	~smart_ptr() { if (_ptr) delete _ptr; }

	T& operator * () { return *_ptr; }
	T* operator & () { return  _ptr; }
	T* operator -> () { return  _ptr; }

	T* get() { return _ptr; }

private:
	T* _ptr{};
};

int main()
{

	int a[] = { 1,2,3,4,5 };
	int* p = a; //int* p = &a[0]

	cout << p << endl;
	//pointer arithmetic
	p++;
	p++;
	p--;
	p = p + 10;

	cout << *p << endl;

	int* ptHeap = new int{ 5 };

	cout << "=================" << endl;
	cout << ptHeap << endl;	
	cout << *ptHeap << endl;

	delete ptHeap;

	{
		smart_ptr<int> sp(new int{ 5 });
		//smart_ptr<int> spc(sp);  -- wont be possible, copy constructor disabled
		unique_ptr<int> up(new int{ 10 });
	}


	_CrtDumpMemoryLeaks();
}