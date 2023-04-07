#include <iostream>


template<typename ... Types> void foo(Types ... args)
{
	// Types : template parameter pack
	// args  : function parameter pack

	// pack 안에 있는 요소의 갯수 구하기
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(Types) << std::endl;
}

int main()
{
	foo(1, 3.4, 'A');
}


