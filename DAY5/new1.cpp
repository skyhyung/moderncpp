// new1.cpp
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()\n"; }
	~Point()            { std::cout << "~Point()\n"; }
};
int main()
{
	// new
	// 1. 메모리 할당
	// 2. 생성자 호출
	// Point* p1 = new Point(1, 2);

	// 1. 소멸자 호출
	// 2. 메모리 해지
	// delete p1;

	// 1. 메모리만 할당
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));

	// 2. 이미 할당된 메모리에 생성자 호출
	new(p) Point(1, 2);

	// 3. 메모리 해지없이 소멸자만 호출
	p->~Point();

	// 4. 메모리만 해지
	operator delete(p);
}












