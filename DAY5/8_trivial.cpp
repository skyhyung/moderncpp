#include <iostream>
#include <type_traits>

// Trivial : 하는일이 "자명하다" 는 의미의 단어
// => 생성자, 소멸자, 복사, 대입연산자가 하는일이 널리 알려진대로 동작할때
// => 사용자가 만들지 말고, 컴파일 제공..
// 
// Trivial Constructor : 생성자가 하는 일이 없다!

class A {};

class B //: public A
{
//	A a;
public:
//	virtual void foo() {}
};

// 1. 사용자가 만든 생성자가 없고
// 2. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial 하고
// 3. 기반 클래스 없거나, 기반클래스 생성자가 trivial 하고
// 4. 가상함수가 없을때
// 생성자는 trivial 합니다.
// => 객체를 생성해도 실제 생성자 호출은 일어나지 않습니다.


int main()
{
	// B의 생성자는 trivial 할까요 ?
	B* p = static_cast<B*>(operator new(sizeof(B))); // 생성자 호출없이 객체 생성

	new(p) B; // 생성자 호출

	p->foo();

	std::cout << "continue main" << std::endl;
}
