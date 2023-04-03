// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 의 용도
// 1. 함수가 예외가 있는지 조사
// 2. 함수가 예외가 없음을 알림.

//void foo()			// 예외 가능성이 있는 함수
void foo() noexcept		// 예외가 없다고 컴파일러에게 알린다.
{
}
void goo()
{
	if (1) // 실패
		throw std::bad_alloc();
}
int main()
{
	// noexcept( 함수 호출식 ) : 실제 함수가 호출되는 것은 아님
	//							표현식대로 함수를 호출했을때 예외가능성이
	//							있는지 조사
	// 원리 : 함수 선언 뒤에 noexcept 를 붙였는지 조사
	// => 결국 함수 제작자가 함수에 예외가 없음을 알려야 한다.
	bool b1 = noexcept(goo());

	std::cout << b1  << std::endl;

	bool b2 = noexcept(foo());

	std::cout << b2 << std::endl;


	// 참고 : 평가되지 않은 표현식(unevaluated expression )
	// => 컴파일 시에만 사용하고 실행시에는 실행되지 않은 표현식
	sizeof(foo()); // foo의 반환값의 크기 조사
	typeid(foo()); // foo의 반환타입의 정보 
	decltype(foo()); //foo의 반환타입 과 같은 타입
	noexcept(foo()); // 예외가 없는가 ?

}




