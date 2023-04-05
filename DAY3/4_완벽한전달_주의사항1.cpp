// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg) // int&& arg = 0
{
	f(std::forward<T>(arg));
}
void foo(int* p) {}

int main()
{
	foo(0); // ok

//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok

	// 핵심 : 완벽한 전달을 사용하는 모든 코드에서는
	//			포인터 의미의 0을 사용할수 없습니다.
	//			nullptr 사용하세요
	//			emplace_back, make_shared 등
}









