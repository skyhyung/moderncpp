#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


// 결론. 완벽한 전달을 하려면
// 1. 인자를 T&&로 받으세요
// 2. 받은 인자를 다른 함수에 보낼때는 "std::forward<T>(arg)" 로 묶어서
//    보내세요

// T&& 는 주로 완벽한 전달에서 사용된다고 해서 이름을
// "forwarding reference" 라고 정했습니다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10); 
	chronometry(goo, n);  
}
