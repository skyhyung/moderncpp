struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}
