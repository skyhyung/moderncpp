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

int main()
{
	foo(&add);

	foo([](int a, int b) { return a + b; });
	foo([](int a, int b) { return a - b; });

	foo(std::less<int>());

	BigFO f;
	foo(f);
}


