// 3_초기화3-1
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
void f1(Point pt) {}
void f2(int n) {}

int main()
{
	int n = 3;
	f2(3);
}
