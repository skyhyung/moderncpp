// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

template<typename F, typename T>
void chronometry(F f, T arg)
{
	// <<======= 시간 기록
	f(arg);
	// <<======= 소요된 시간 출력
}

int main()
{
	int n = 10;

	foo(10);
	goo(n);

	std::cout << n << std::endl;
}
