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
//	Point* p2 = new Point[10]; // error. 디폴트 생성자가 없습니다.

//	Point* p2 = new Point[10]{ {0,0},{0,0};

	// 생성자 호출과 메모리 할당을 분리하면 유연성이 좋아집니다.

	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 이미 할당된 10개의 메모리에 객체를 생성 합니다.(생성자 호출을 의미)

	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}

	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	operator delete(p2);

}












