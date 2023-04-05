#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 핵심 : int& 와 int&& 버전을 2개 제공해야 합니다.
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}
