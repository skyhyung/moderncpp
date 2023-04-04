#include <iostream>
#include <string>

// rule of 0
// => 자원 관리는 자원 관리 객체에 의존하자.
// 문자열 : char* => std::string
// 버퍼   : int*  => std::vector 또는 스마트 포인터

// 사용자가 자원할당하지 않으면(복사, move 모두 만들지 않으면)
// => C++ 컴파일러가 모두 제공한다!!
class Cat
{
	std::string name;
	int   age;
	std::string address;
public:
	Cat(const std::string& n, int a, const std::string& s = "unknown")
		: name(n), age(a), address(s)
	{
	}
};




int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}





