// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt(0, 0);

	Point& r1 = pt;
	Point& r2 = Point(0, 0);
}