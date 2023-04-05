#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main						chronometry				hoo(int&&)
// hoo(10) ============================================> ok
// chronometry(10) ========> int&& arg = 10
//							hoo(arg) ==================> error(arg는 lvalue)
//							hoo(static_cast<int&&>(arg)) ==> ok

template<typename F> void chronometry(F f, int&& arg)
{
	// 인자를 받을때 "int&& arg = 10" 이 된다.
	// => 상수성도 추가되지 않고, 복사본도 없지만
	// => rvalue 인 10을 받으면서 arg라는 이름이 생겨서 lvalue
	//	  로 변경
//	f(arg); // hoo(int&) 를 찾게 되므로 error
	f(static_cast<int&&>(arg)); // ok!!!
}

int main()
{
	chronometry(hoo, 10);	
}
