// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {} // call by value : 복사본 생성
void f2(Point& pt) {} // call by value : 복사본 생성 안됨

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}

//--------------------------------------------

Point pt(1, 2);

Point foo()		// return by value
{				// pt를 반환하는 것이 아니라
	return pt;  // pt를 복사한 임시객체를 반환
}				// 리턴용 임시객체는 함수 호출 문장 끝에서 파괴

Point& goo()	// return by reference
{
	return pt;	// 복사본이 아닌 pt의 alias 반환
}

int main()
{
	foo().x = 10; // error. 임시객체는 등호의 왼쪽에 올수 없다
	goo().x = 10; // ok
}





