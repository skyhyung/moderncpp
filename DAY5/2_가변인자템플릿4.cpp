#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	// printv(args...);	// error. printv(1,2,3) 으로 생성됨..

	// printv(args)...;	// printv(1), printv(2), printv(3) 라는 의도
			 	// error

	// Pack Expansion 은 아래의 코드에서만 사용가능합니다.
	// 1. 함수의 인자 () 안에서
	// 2. {} 초기화 구문 안에서
	// 3. template 인자 <> 안에서

	int x[] = { 0, (printv(args), 0)... }; 
			// { (printv(1), 0), (printv(2), 0), (printv(3), 0) }
}

 
int main()
{
	foo();
	foo(1, 2, 3);
}

