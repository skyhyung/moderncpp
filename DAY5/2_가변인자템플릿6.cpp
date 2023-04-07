#include <iostream>

// 233 page 입니다.

// 1. 1번째 인자는 가변인자가 아닌 이름있는 독립된 인자로 받으세요

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

	std::cout << n << " : " << value << std::endl;

//	foo(args...); // foo(3.4, 'A') => value : 3.4   args : 'A'
				  // foo('A')      => value : 'A'   args : 
				  // foo()
	// C++17 부터는 아래 처럼 하세요
	if constexpr (sizeof...(args) > 0)
		foo(args...);
				  
}

int main()
{
	foo(1, 3.4, 'A'); 
}





