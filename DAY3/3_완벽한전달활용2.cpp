#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// ����Ʈ ������
	// 1. ���� ��ü ����
	// �Ʒ� �ڵ�� ���� �޸𸮸� ��� �Ҵ� �ұ�� ?
	std::shared_ptr<Point> sp1(new Point(1,2));
}







