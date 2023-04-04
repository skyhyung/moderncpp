// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}
void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	Point p1(1, 2);
	Point p2(10, 20);

	draw_line(p1, p2);

	// 핵심 1. 인자로만 사용되는 객체를 임시객체 형태로 
	//        만드는 것이 효율적이다
	draw_line(Point(1, 1), Point(10, 10));


	// 핵심 2. 임시객체는 상수 참조로는 가리킬수 있지만
	//		   상수가 아닌 참조로는 가리킬수 없다.
	//			=> 이유를 잘 생각해 보세요
	//			=> 상수가 아닌 참조는 객체를 수정하겠다는 의도 인데..
	//			   임시객체를 수정하는 것은 논리적으로 틀리다
	Point pt(10,10);
	init(pt); // pt 를 0, 0으로 reset

	init(Point(10, 10)); // error
	

	std::cout << "-----" << std::endl;
}





