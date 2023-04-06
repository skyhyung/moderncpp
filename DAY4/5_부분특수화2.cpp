#include <iostream>
using namespace std;
// 160 page

template<typename T, typename U> struct Object
{
	static void foo() { std::cout << "T, U" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { std::cout << "T*, U*" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { std::cout << "T*, U" << std::endl; }
};
// 핵심 : primary template 템플릿 인자가 2개 일때
// 1. 사용자는 반드시 2개 전달해야 한다. Object<int, int>
// 
// 2. 부분 특수화시 템플릿 인자 갯수는 바뀔수 있다 - 아래 참고

// 3. 부분 특수화 모양을 표기할 때는 반드시 인자가 2개 - Object<T,T>
template<typename T> struct Object<T, T>
{
	static void foo() { std::cout << "T, T" << std::endl; }
};

template<> struct Object<int, short>
{
	static void foo() { std::cout << "int, short" << std::endl; }
};

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	Object<int, Object<double, char>::foo();
								// T, Object<U, V>   나오게 해보세요
}

