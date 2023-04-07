// new1.cpp
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()\n"; }
	~Point() { std::cout << "~Point()\n"; }
};
int main()
{
	// 힙에 객체 한개 만들기
	Point* p1 = new Point(1, 2);

	// 힙에 객체 10개 만들어 보세요.(연속된 메모리에)
}












