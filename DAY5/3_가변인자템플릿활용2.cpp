#include <iostream>

int f(int, double, char) { return 0; }

// 1. 사용하는 코드는 보고 primary template 을 만듭니다.
template<int N, typename T>
struct argument
{
	using type = T;
};
// 2. 원하는 정보를 얻을수 있도록 부분특수화를 해야 합니다.
/*
template<int N, typename R, typename ... ARGS>
struct argument<N, R(ARGS...)>
{
	// R(ARGS...) 에서 N번째 인자의 타입은 ??
	// => 구할수 없다. 잘못된 부분 특수화
	using type = ? ;
};
*/
// N == 0 을 먼저 생각
/*
template<typename R, typename ... ARGS>
struct argument<0, R(ARGS...)>
{
	// R(ARGS...) 에서 0번째 인자의 타입은 ?
	// => 구할수 없다. 잘못된 부분 특수화
	using type = ? ;
};
*/

template<typename R, typename T, typename ... ARGS>
struct argument<0, R(T, ARGS...)>
{
	using type = T ;
};

// N != 0 일때만 해결하면 됩니다.
template<int N, typename R, typename T, typename ... ARGS>
struct argument<N, R(T, ARGS...)>
{
	// R(T, ARGS...) 의 1번재 인자의 타입은
	// R(ARGS...)    의 0번재 인자의 타입과 동일합니다.

	using type = typename argument<N - 1, R(ARGS...)>::type;
};


template<typename T> void foo(T& t)
{
	// 인자의 타입 구하기
	// T : int(int, double, char)
	//typename argument<0, T>::type n; // int n
	typename argument<1, T>::type n; // int n

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}
