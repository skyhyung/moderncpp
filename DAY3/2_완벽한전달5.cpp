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
	// static_cast<int&&>(arg) : rvalue 로 캐스팅하는 코드
	// static_cast<T&&>(arg)   : rvalue 로 캐스팅하는 코드가 아닙니다.

	// 아래 캐스팅은 chronometry 의 2번째 인자로
	// rvalue 를 (전달하면, arg를) rvalue 로 캐스팅하고
	// lvalue 를 (전달하면, arg를) lvalue 로 캐스팅하는 코드입니다(필요없는코드
	//													컴파일러에의해 제거됨)

	f(static_cast<T&&>(arg));
}
int main()
{
	int n = 0;
	chronometry(foo, 10); // T= int, chronometry( , int&& )
						  // => static_cast<int&&>(arg)

	chronometry(goo, n);  // T= int&, chronometry( , int& )
						  // => static_cast<int&>(arg)
}
