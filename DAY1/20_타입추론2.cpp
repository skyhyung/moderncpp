#include <iostream>

// 규칙 1. 템플릿 인자가 값 타입 일때( T a )
// => 함수 인자가 가진 "const, volatile, reference" 속성을 제거하고
//    T의 타입 결정

template<typename T> void foo(T a)
{
	a = 100;
}
int main()
{
	// 타입을 명시적으로 전달하는 경우
	// => 무조건 사용자가 전달한 타입 사용
	foo<int>(3.4); // T=int

	// 타입을 명시적으로 전달하지 않으면 함수 인자로 추론
	// T의 타입을 예측해 보세요
	foo(10); // T = int
	foo(3.4);// T = double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);	// T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int
}



