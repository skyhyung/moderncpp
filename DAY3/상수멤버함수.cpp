// github.com/codenuri/moderncpp 에서 DAY3.zip 받으시면 됩니다.
// 상수멤버함수
class Point
{
public:
	int x, y;
	void set(int a, int b) { x = a; y = b; }

	// 핵심 1. 상수 객체는 상수 멤버 함수만 호출가능합니다
	// 2. print 같은 멤버 함수는 상수객체라도 사용가능해야 합니다.
	//    "반드시" 상수 멤버함수로 해야 합니다.
	// 3. 원리 : 상수 멤버 함수는 객체를 받을때 const * 로 받는것!

//	void print()		// void print(Point* this)
	void print() const	// void print(const Point* this)
	{
	}
};
int main()
{
	const Point pt;
//	pt.x = 10;		// error. public 에 있지만 상수 이므로
//	pt.set(10, 20);	// error. 
	pt.print();		// error	
					// 멤버 함수의 원리 : print(&pt)
}
