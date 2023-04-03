#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	Point() : Point(0,0)   // C++11 부터 다른 생성자 호출가능
							// "위임 생성자"라는 문법
	{
//		Point(0, 0); // 다른 생성자 호출이 아니라!!
					 // 이순간 이름없는 객체(임시객체)를 만들게 됩니다
					// C++11 이전까지는 생성자에서 다른 생성자 호출 안됩니다.
	}
	Point(int a, int b) :  x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

