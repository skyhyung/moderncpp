class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // �� �ڵ尡 �� ������ ������ ?
				  // �����Ϸ��� ������ִ� ��������ڻ��
}