// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
			// class xxx{ operator()(int, int) {} }; xxx();			

	auto f2 = [](int a, int b) { return a + b; };
			// class yyy{ operator()(int, int) {} }; yyy();			

	// 핵심 : 모든 람다 표현식은 다른 타입 입니다.
	// => 아래 처럼 타입 이름을 출력해 보거나, godbolt 에서도 확인됩니다.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	
	// 람다표현식으로 초기화된 f3 변수에는 
	// 다른 람다 표현식을 담을수 없습니다.
	// => 모두 다른 타입이므로!
	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error
}





