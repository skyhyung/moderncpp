#include <iostream>

// function object(�Լ� ��ü)
// => () �����ڸ� ������ �ؼ� �Լ� ó�� ��밡���� ��ü

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};


int main()
{
	Plus p;		

	int n = p(1, 2);	
	
}
