// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 방법 1. call by value
	// => 복사 생성자가 무한히 호출되는 코드
	// => error.
	// => 복사생성자는 1번째 인자가 "값 타입"일수 없다.
//	Point(Point pt) {} // Point pt = p2;

	// 방법 2. call by reference
	// => 에러 아님. 
	// => rvalue 를 받을수 없다.
	// => 값을 반환하는 함수의 결과를 받을수 없다.
	// Point(Point& other) {}

	// 방법 3. lvalue 와 rvalue 를 모두 받을수 있다.
	// => 일반적인 복사 생성자의 모양
	Point(const Point& other) : x(other.x), y(other.y) {}
};
Point foo()
{
	Point p(1, 2);
	return p;
}

int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);			

	Point ret = foo();
}




