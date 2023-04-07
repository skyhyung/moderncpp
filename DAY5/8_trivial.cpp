#include <iostream>
#include <type_traits>

// Trivial : 하는일이 "자명하다" 는 의미의 단어
// => 생성자, 소멸자, 복사, 대입연산자가 하는일이 널리 알려진대로 동작할때
// => 사용자가 만들지 말고, 컴파일 제공..
// 
// Trivial Constructor : 생성자가 하는 일이 없다!

class A {};

class B 
{
public:
	virtual void foo() {}
};

int main()
{
	// B의 생성자는 trivial 할까요 ?
	B* p = static_cast<B*>(sizeof(B)); // 생성자 호출없이 객체 생성

	p->foo();

	std::cout << "continue main" << std::endl;
}
