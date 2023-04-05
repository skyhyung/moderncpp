// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 방법 1. 객체 생성후 넣기
//	Point pt(1, 2);
//	v.push_back(pt);

	// 방법 2. 임시객체로 넣기
	//v.push_back(Point(1, 2));

	// v.push_back({1,2}); // 위와 동일합니다.
						// {1,2} 로 임시객체 만든것
	
	// 방법 3. 핵심!!!
	// => 객체를 만들어서 전달하지 말고
	// => 객체를 만들기 위한 생성자 인자(x, y값)을 전달하자.
	v.emplace_back(1, 2);
			// emplace_back 에서
			// "new Point(전달된 인자들)" 로 버퍼에 만들게 됩니다.

	std::cout << "-----" << std::endl;
}
/*
template<typename T>
class vector
{
public:
	template<typename ... A>
	void emplace_back(A&& ... arg)
	{
		new T(std::forward<A>(arg)...);
	}
};
vector<Point> v;
v.emplace_back(1, 2);
*/




// 1. 컨테이너가 primitive 타입을 저장할때
// => emplace 도 가능하지만 push_xxx 사용하세요
vector<int> v;
v.push_back(10);

// 2. 컨테이너가 user define 타입을 값으로 저장할때
// => push_xxx 보다 emplace_xxx 가 성능이 좋습니다.
// => push_back  => emplace_back
//    push_front => emplace_front
//    insert     => emplace
vector<Point> v;
v.push_back(Point(1, 2)); // 이렇게 하지말고
v.emplace_back(1, 2); // 이렇게 하세요




