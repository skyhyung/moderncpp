// 2_완벽한전달8.cpp -> 5_move추가0.cpp 로 이름 변경
#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() {}
	Object(const Object& o)     { std::cout << "copy" << std::endl; }
	Object(Object&& o) noexcept { std::cout << "move" << std::endl; }
};
// 핵심 1. 템플릿 만들때 인자를 T& 로 할지 ? T&&로 할지 잘 구분하세요
// T&  : lvalue 만 받겠다
// T&& : lvalue, rvalue 모두 받겠다

// C++ 표준의 move 를 직접 구현해 봅시다.
template<typename T>
typename std::remove_reference<T>::type&& move(T&& obj)
{
	// static_cast<T&&> : rvalue 캐스팅 아닙니다.
	//					=> 이건 std::forward<T> 의 원리 입니다.
	//					=> rvalue 를 rvalue 로 
	//					   lvalue 를 lvalue 로 캐스팅

	// static_cast< "T안에 포함수 레퍼런스를 제거한 타입" &&> 
	//						=> rvalue 캐스팅 입니다.

	return static_cast<typename std::remove_reference<T>::type &&>(obj);
}
int main()
{
	Object o1;
	Object o2 = o1;  	  // copy
	Object o3 = move(o1); // move
						  // 
	Object o4 = move(Object()); // move
}



// 정리
template<typename T>
void foo(T&& arg)
{
	// 핵심 : T&& 가 rvalue reference 아니라고 기억하세요

	std::move(arg); // arg 를 무조건 "rvalue"  로 캐스팅
					// static_cast<T안에레퍼런스제거후 &&>(arg)

	std::forward<T>(arg); // arg 에 전달된 인자에 따라 다른 캐스팅
						// static_cast<T&&>(arg)
						
						// rvalue 를 보냈으면 rvalue 캐스팅
						// lvalue 를 보냈으면 lvalue 캐스팅
}
foo(n);
foo(10);





