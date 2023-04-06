#include <iostream>
#include <type_traits>

template<typename T> void printv(const T& v)
{
	// if : 실행시간 제어문 조건이 false 라도 "템플릿 => 함수생성" 에 포함됨

	// if constexpr : 컴파일 시간 제어문
	//					조건이 false 라면 "함수 생성시 포함안됨"
	// 
//	if ( std::is_pointer_v<T> )
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n); // 이순간 에러!
	printv(&n); // ok
}

