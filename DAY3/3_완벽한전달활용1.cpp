// 8_�Ϻ�������Ȱ��
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	// 1. 
	Point pt(1, 2);
	v.push_back(pt);

	std::cout << "-----" << std::endl;
}


