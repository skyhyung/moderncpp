#include <iostream>
#include <string>
#include <vector>

// �� move�� �߿��Ѱ� ? - 101 page �Ʒ� �ֽ��ϴ�.

template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}



