#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// 완벽한 전달을 하려면
// 1. int&, int&& 버전으로 따로 만들고
// 2. int&& 버전에서는 인자를 전달할때 "static_cast<int&&>(arg)" 로전달
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}

int main()
{
	chronometry(hoo, 10);
}
