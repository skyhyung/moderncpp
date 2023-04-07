#include <iostream>

// 핵심 1. 변수, 함수의 선언문에서 "이름"을 제외하면 타입이 됩니다.

// f의 타입 : int(int, double)   => 함수 타입
//           int(*)(int, double) => 함수 포인터 타입

int f(int a, double b) { return 0; }

// 함수의 리턴 타입을 구하는 traits 를 만들어 봅시다
template<typename T> 
struct result
{
	using type = T;
};

// 핵심 : 원하는 타입을 얻을수 있도록 부분 특수화를 해야 합니다.
// => 이부분이 이 예제의 핵심
// => int(int, double) => int 와 (int, double)을 분리!
// => 아래 코드는 인자가 2개인 함수만 됩니다.
/*
template<typename R, typename A1, typename A2>
struct result< R(A1, A2) >
{
	using type = R ;
};
*/
// 아래 처럼 만들면 모든 함수의 반환타입을 구할수 있습니다.
template<typename R, typename ... ARGS>
struct result< R(ARGS...) >
{
	using type = R;
};

template<typename T> void foo(T& a) 
{
	// 현재 T : int(int, double)
	typename result<T>::type n;  // int n

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);
}
