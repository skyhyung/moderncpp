#include <iostream>

// 타입을 확인하는 방법

template<typename T> void foo(T a)
{
	// 1. typeid() 사용
	std::cout << typeid(T).name() << std::endl;
}


int main()
{
	foo<int>(3.4); // T=int

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);	// T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int
}



