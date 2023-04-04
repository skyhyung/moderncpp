// 1_초기화11 - 65 page..
// aggregate initialization
// aggregate type
// => 생성자가 없어도 {}로 초기화 가능한 타입
// => 배열, C 구조체등.
struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	void f1() {} // 있어도 aggregate

//	virtual void f2() {} // 가상함수가 있으면 aggregate 아님

//	Point() {};	// error. 생성자를 제공하는 aggregate 아님

	Point() = default; // ok.컴파일러가 만든 생성자는 있어도 aggregate
						// 단, C++20 부터는 안됨!! error
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
}
