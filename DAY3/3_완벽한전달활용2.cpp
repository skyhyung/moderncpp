#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ?
	//std::shared_ptr<Point> sp1(new Point(1,2));

	// 스마트 포인터 사용시 std::make_shared<> 를 사용하는것이
	// 좋습니다.
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);
				// 1. sizeof(Point) + sizeof(관리객체)를 한번에 할당
				// 2. 인자로 전달받은 1,2 를 가지고 Point 생성자 호출
				// 3. 생성된 객체를 관리하는 shared_ptr을 만들어서 반환
}








