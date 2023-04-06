// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	// 핵심 : 함수 찾는 순서 알아 두세요
	foo(3); // 1. int - exactly matching
			// 2. T
			// 3. ...
			// 4. 3개 모두 없으면 함수가 없다는 에러
}
