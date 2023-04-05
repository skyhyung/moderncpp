#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));	// 필요없는 캐스팅입니다.
								// 아무일도 하지 않는 코드
								// 컴파일시에 제거됩니다.
						// 아래 int&& 버전과 구현을 동일하게 하려고!
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// T&& 를 사용하면
// 1. 위 2개 자동생성됩니다.
// 2. 인자 타입이 int 뿐아니라 모든 타입이 사용가능합니다.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}
int main()
{
	int n = 0;
	chronometry(foo, 10); // chronometry( , ? )
						  // => static_cast<?>(arg)
	chronometry(goo, n);  // chronometry( , ? )
						  // => static_cast<? >(arg)
}
