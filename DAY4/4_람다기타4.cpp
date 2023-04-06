#include <iostream>

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 지원하기 위해
	// "operator()" 와 동일한 일을 하는 static 멤버 함수가 생성됨
	inline static int helper(int a, int b) { return a + b; }

	using PF = int(*)(int, int);

//	operator PF() { return &CompilerGeneratedName::operator(); }
		// => error. 멤버 함수 주소는 일반 함수 포인터와 호환되지 않는다

	operator PF() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int(*f)(int, int) = CompilerGeneratedName();
						// 객체.operator 함수포인터타입() 

	std::cout << f(1, 2) << std::endl;


//	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx();
}












