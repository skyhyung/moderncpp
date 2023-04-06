#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }


int foo(...) { std::cout << "..." << std::endl; return 0; }


int main()
{
	foo(3); // 1. 인자인 3을 보고 "foo(T)"버전 선택
			// 2. T=int 를 정하고 함수를 생성하다가 실패 하면
			//    => 에러는 아니고 후보에서 제외된다.
			//	  => 동일 이름의 다른 함수가 있다면 사용

	// Substitution Failure Is Not An Error => SFINAE
}
