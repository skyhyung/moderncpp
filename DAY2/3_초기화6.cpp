// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};
int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 }; // copy initialization
	int n3;			// default initialization - 쓰레기값
	int n4{};		// value initialization
					// primitive 타입은 0으로 초기화

	std::cout << n4 << std::endl; // 0

	Point pt{};		// x, y 가 모두 0으로 초기화
					// 단, 사용자가 생성자를 직접 구현한 경우는
					// 0 초기화 안됨
	std::cout << pt.x << std::endl;
}


