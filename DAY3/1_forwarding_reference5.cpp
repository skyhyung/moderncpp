#include <iostream>

// 이 부분을 학습하실때 꼭 아래처럼 함수 이름 출력해 보세요
// 또는 godbolt.org 에서 확인
template<typename T> void foo(T&& arg)
{
	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 10;

	foo(n);  // T= int&, T&& = int&
	foo(10); // T= int,  T&& = int&&
}




