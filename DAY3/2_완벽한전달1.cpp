// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding : 전달 받은 인자를 다른 함수에 보내는 것
// perfect forwarding 
// => 어떠한 변화도 없이 인자를 다른곳에 완벽하게 전달하는 기술

template<typename F, typename T>
void chronometry(F f, const T& arg)
{
	// <<======= 시간 기록
	f(arg);
	// <<======= 소요된 시간 출력
}
int main()
{
	int n = 10;

	chronometry(foo, 10);  // foo(10)
	chronometry(goo, n);   // goo(n);

	std::cout << n << std::endl;
}
