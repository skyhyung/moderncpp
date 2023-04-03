#include <iostream>

// 참고로 알아 두세요
int x = 0;

int  f1() { return x; } // x의 값, 0을 반환
int& f2() { return x; } // x변수의 별명을 반환

int main()
{
	f1() = 20; // error. 0 = 20
	f2() = 20; // ok.    x = 20

	// 즉, 함수가 참조를 반환하면 등호의 왼쪽에 올수 있습니다.
}
