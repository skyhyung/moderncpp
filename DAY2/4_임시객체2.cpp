// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error. 임시객체는 등호의 왼쪽에 올수 없다
						// lvalue 가 될수 없다.

	Point* p1 = &pt;			// ok	
	Point* p2 = &Point(1, 2);	// error. 임시객체는 & 연산자로
								// 주소를 구할수 없다. 

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	const Point& r3 = Point(1, 2);	// ok. 임시객체를 상수 참조로 
									// 가리킬수 있다.
									// draw_line()에서 인자로 받기 위해
									// 만든 문법
								// 임시객체의 수명이 r3의 수명으로 연장
								// "lifetime extension" 이라는 개념

	// C++11 부터, 상수성없이 임시객체를 가리키는 참조가 필요 했습니다.
	// => rvalue reference
	// => move 를 만들기 위해 필요 했음..
	Point&& r4 = Point(1, 2); // ok
	r4.x = 10; // ok..     
}





