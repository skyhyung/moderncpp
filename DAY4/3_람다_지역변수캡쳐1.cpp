// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수
	// => 전역변수는 프로그램의 모든 함수에서 접근가능하다.
	auto f1 = [](int a) { return a + g; };  // ok

	// 2. 람다표현식에서 main 함수 지역변수
	// => 지역변수를 캡쳐해야지 접근 가능합니다.
//	auto f2 = [](int a) { return a + v1 + v2; };  // error

	auto f2 = [v1, v2](int a) { return a + v1 + v2; };  // ok

	auto f3 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; };//error

	auto f4 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };//ok
}





