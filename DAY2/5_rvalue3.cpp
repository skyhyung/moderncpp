#include <iostream>
#include <type_traits>

// 표현식이 lvalue 인지 rvalue 인지 조사하는 방법

int main()
{
	int n = 10;

	n + 10;

	if (std::is_lvalue_reference<decltype(n + 10)>::value)
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;
}
