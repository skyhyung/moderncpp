
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 핵심 : 디폴트 생성자가 없는 타입을 멤버데이타로 가진 경우
class Rect
{
	Point pt; // ?
public:
	// 사용자가 만든 코드		// 컴파일러가 변경한 코드
//	Rect() {}				// Rect() : pt() {}

	// C++98 해결책 : 생성자에서 멤버 데이타의 다른 생성자를 명시적으로 호출
	Rect() : pt(0, 0) {}
};

// C++11 이후에 가능한 다른 해결책
class Rect2
{
	Point pt{ 0, 0 }; // ok

//	Point pt(0, 0); // error. 컴파일러가 pt를 함수로 해석
};


int main()
{
	Rect r1;
}

