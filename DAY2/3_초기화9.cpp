// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);		// Point(int) 호출
	Point p2(1, 2);		// Point(int, int) 호출
	Point p3({ 1,2 });  // Point(initializer_list) 호출
	
	Point p4{ 1,2 };	// 1. Point(initializer_list) 있으면 사용
						// 2. 없으면 Point(int,int) 사용
	
	Point p5(1, 2, 3);	// error. Point(int, int, int) 는 없다
	Point p6{ 1, 2, 3 };// ok. Point(initializer_list)
	Point p7 = { 1,2,3 };//ok. Point(initializer_list)

	// 결론 : 생성자 인자로 initializer_list 를 받으면
	//		  동일타입의 값을 몇개라도 보낼수 있다.

	std::vector<int> v1 = { 1,2,3,4,5,6,7 };
	std::vector<int> v2 { 1,2,3,4,5,6,7 };

	
}




