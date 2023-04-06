// 7_�����������ø�7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

