// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 디폴트 생성자를 만드는 2가지 방법
//	Point() {}	// 방법 1. 사용자가 직접 만든다.

	Point() = default; // 방법 2. 컴파일러에게 만들어 달라고 요청
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




