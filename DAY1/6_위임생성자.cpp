#include <iostream>
// 6_���ӻ����� - 24page
class Point
{
public:
	int x, y;
public:
	Point() 
	{
	}
	Point(int a, int b) : x(a), y(b)
	{
		// ������ �ʱ�ȭ �ڵ�
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

