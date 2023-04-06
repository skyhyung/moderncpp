// 1_function_argument4
#include <string>
#include <string_view> 
#include <iostream>

int main()
{
	// 아래 코드를 생각해 보세요
	auto p = std::begin( std::string("hello") );
	auto c = *p; // 안전할까요 ? 
				 // p 가 가리키던 곳이 파괴 되었습니다. 
				 // 절대 사용하며 안됩니다

	std::string s = "hello";

	// 아래 코드의 p2 반복자는 어떨까요??
	auto p2 = std::begin(std::string_view(s));
	
}
