// github.com/codenuri/moderncpp 에서 DAY3.zip 받으시면 됩니다.
// 상수멤버함수
class Point
{
public:
	int x, y;
	void set(int a, int b) { x = a; y = b; }

	void print()
	{
	}
};
int main()
{
	const Point pt;
	pt.x = 10;
	pt.set(10, 20);
	pt.print();
}
