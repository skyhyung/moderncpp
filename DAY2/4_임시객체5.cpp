#include <iostream>
// 85 page
struct Base
{
	int value = 10; // c++11 부터 이렇게 초기화가능
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;  // 20

	std::cout << static_cast<Base&>(d).value << std::endl;  // 10
	std::cout << static_cast<Base>(d).value << std::endl;  // 10


	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30;  // error
}

// 핵심. 임시객체는
// 1. 사용자가 직접 만들기도 하고 - 주로 함수 인자. 
//   => draw_line(Point(0,0), Point(1,1));

// 2. 값을 반환하는 함수나, 값 캐스팅 등에서 생성되기도 한다
