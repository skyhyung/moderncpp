// 후위반환 - 73 page 아래 부분
#include <iostream>

template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

