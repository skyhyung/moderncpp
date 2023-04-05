#include <vector>
#include <iostream>

int main()
{
	std::vector<int>  v1(10, 0);
	std::vector<bool> v2(10, 0);

	// a1, a2의 타입은 ?
	auto a1 = v1[0];
	auto a2 = v2[0];

	std::cout << typeid(a1).name() << std::endl;
	std::cout << typeid(a2).name() << std::endl;

	

}

