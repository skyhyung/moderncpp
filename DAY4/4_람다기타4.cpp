#include <iostream>

// 아래 코드에서 
// => 지역변수를 캡쳐한 람다는 멤버 데이타가 추가 되는데
// => "helper" 는 static 이므로 일반 멤버 데이타 접근 안됩니다.(static 멤버 데이타는 접근 가능)
// => 하지만 람다 표현식에서 캡쳐 하면 일반 멤버 데이타로 만들어지니 helper는 접근 안됨.
// => 그래서 C++ 문법에서
//    "캡쳐하지 않은 람다 표현식"만 함수 포인터로 변환 가능합니다.

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


	int v1 = 10;

//	int(*f)(int, int) = [v1](int a, int b) {return a + b + v1; };
						// class xxx{}; xxx();
}












