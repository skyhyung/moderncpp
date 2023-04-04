// 3_초기화1-1

class Point
{
	// C++11. field initialization
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int b) : y(b) {}
};

// 위 코드를 컴파일러는 아래 처럼 변경합니다.
class Point
{	
	int x; // = 0;
	int y; // = 0;
public:
	// 위 필드 초기값을 컴파일러가 생성자의 초기화 리스트에 추가
	Point()      : x(0), y(0) {}
	Point(int b) : x(0), y(b) {}
};
int main()
{

}


