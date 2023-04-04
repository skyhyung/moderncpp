#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4); // ret 타입은 ?  int
	ret = 100; // x가 변경되는 것 아님. 

	// decltype( 함수호출식 ) : 함수의반환 타입 조사
	//							실제 함수가 호출되는 것은 아님.
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4); // ret2는 참조타입
	ret2 = 200;

	// C++14 의 decltype(auto)
	// => 우변의 표현식을 auto 자리에 놓아달라.
	// => 우변으로 타입을 결정하는 decltype 규칙으로!
	decltype(auto) ret3 = foo(1, 3.4);

	std::cout << x << std::endl; 
}
