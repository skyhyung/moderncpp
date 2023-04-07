#include <tuple>
#include <iostream>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);
	
	std::cout << p.first << std::endl; // 1
	

	std::pair<int, std::pair<double, char>> p3(10, { 3.4, 'A' });

	std::cout << ? << std::endl; // 3.4

}
