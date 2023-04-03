// 초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;
	int value2 = ++x;
public:	
	Test() {}
	Test(int n) : value2(n) {}
};

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요. ?
}