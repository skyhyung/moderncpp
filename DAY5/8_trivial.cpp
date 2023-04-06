#include <iostream>
#include <type_traits>

// Trivial : 하는일이 "자명하다" 는 의미의 단어
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
}