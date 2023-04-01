#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	Point() 
	{
	}
	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

