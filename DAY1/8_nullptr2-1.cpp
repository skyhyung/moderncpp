// 8_nullptr2-1
#include <iostream>

void foo(int* p) {}

// 함수와 인자를 받아서 함수에 인자를 전달하는 함수
template<typename F, typename A>
void chronometry(F f, A a)	// int a = 0;
{
	// 시간기록
	f(a);					// foo(a)
	// 함수 수행시간 출력
}
int main()
{
	int n = 0;
	foo(0); // ok
//	foo(n); // error
//	chronometry(foo, 0); // foo(0) 의 수행시간을 측정하려는 의도
						// error.
	chronometry(foo, nullptr); // ok.!!! 이럴때사용하려고 nullptr
								// 을 만든것
}







