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
	// => string_view 는 자원의 소유자가 아니므로 안전합니다.
	auto p2 = std::begin(std::string_view(s));

	// 결국. 
	// 자원의 소유자 인지 ?
	// 자원을 빌려서(Borrow) 사용하는지가 중요해 집니다.
	// => 그래서 C++20 부터 "borrowed range" 라는 개념이 등장합니다.
	// => 그리고 std::range::begin() 이 이 개념을 도입해서 만든 begin
	// => Rust 에서 "대여(borrow)" 가 핵심 기술입니다.
	
}
