#include <functional>

int add(int a, int b) { return a + b; }

class BigFO
{
	int x[32];
public:
	inline int operator()(int a, int b) // <== const 멤버 함수아님
	{ 
		x[0] = 10;
		return a + b; 
	}
};
// () 로 호출가능한것 : 일반함수, 함수객체, 람다표현식
// foo 을 만드는 최선의 코드를 생각해 봅시다.

// 방법 1. 함수 포인터
// => 일반 함수, 캡쳐되지 않은 람다는 전달 가능
// => 캡쳐한 람다, std::less<>, 함수 포인터 변환연산자가 없는 객체 안됨
// => 장점 : template 아님. 코드 증가 안됨.
void foo( int(*f)(int, int) ) {}

int main()
{
	foo(&add);

	foo([](int a, int b) { return a + b; });

	int v1 = 10;
	foo([v1](int a, int b) { return a - b + v1; });

	foo(std::less<int>());

	BigFO f;
	foo(f);
}


