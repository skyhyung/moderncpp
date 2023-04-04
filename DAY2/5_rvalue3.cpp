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
	CHECK_VALUE_CATEGORY("AAAA");

	// 문자열 리터럴은 lvalue 입니다.
	// 데이타 메모리(상수메모리)를 사용하게 되고
	// 계속 메모리에 남아 있는 존재하는 
	"AAA"[0] = 'S'; // lvalue 인데 왜?? 에러 인가요?
					// lvalue 지만 상수 이므로!!
}
