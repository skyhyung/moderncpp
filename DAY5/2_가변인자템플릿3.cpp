#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	// goo(args); // error. pack 을 직접 전달할수 없습니다.

	// Pack Expansion
	// "pack 을 사용하는 패턴"...   => E1패턴, E2패턴, E3패턴

	goo(args...);  // ok, goo(1, 2, 3)
	goo(++args...);// ok. goo(++E1, ++E2, ++E3) 
				   // 실행후에는 args 는 "2,3,4" 입니다.

//	goo(hoo(args...));	// goo(hoo(E1, E2, E3)) 인데..
						// hoo 는 인자가 한개이므로 error

	goo(hoo(args)...);  // goo( hoo(E1), hoo(E2), hoo(E3)) 
}


int main()
{
	foo(1, 2, 3);
}
