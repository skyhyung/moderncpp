#include <iostream>
#include <type_traits>

// 표현식이 lvalue 인지 rvalue 인지 조사하는 방법

#define CHECK_VALUE_CATEGORY(...)								\
if (std::is_lvalue_reference<decltype((__VA_ARGS__))>::value)	\
	std::cout << "lvalue" << std::endl;							\
else                                                            \
	std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;

	n + 10;

	if (std::is_lvalue_reference<decltype((n))>::value)
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;

	CHECK_VALUE_CATEGORY(++n);
	CHECK_VALUE_CATEGORY(n++);
	CHECK_VALUE_CATEGORY(10);
	CHECK_VALUE_CATEGORY(n);
}
