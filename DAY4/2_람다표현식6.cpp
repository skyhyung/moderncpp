// 145 page
#include <iostream>

int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };
				// class xxx{}; xxx();

	int n = f1(1, 2);
			// 이순간 int 반환

	// return 문장이 한개라면 반환타입 생략가능
	auto f2 = [](int a, int b)  { return a + b; };

	// return 문장이 두개이상이라도 동일타입이면 생략가능
	auto f3 = [](int a, int b) { if (a == 1) return a; return a + b; };

	// 다른 타입을 반환하는 return 문이 있는경우. 반환 타입 명시해야 합니다.
	auto f4 = [](double a, int b) { if (a == 1) return a; return b; };

}

