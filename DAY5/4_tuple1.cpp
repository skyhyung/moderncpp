#include <tuple>
#include <iostream>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);
	
	std::cout << p.first << std::endl; // 1
	

	std::pair<int, std::pair<double, char>> p3(10, { 3.4, 'A' });

	std::cout << p3.second.first << std::endl; // 3.4

	//====================
	// C++11 부터 pair 의 확장 버전이 tuple 제공
	std::tuple<int, double, char, short> t4(1, 3.4, 'A', 2);

	// 요소 접근은 std::get 사용
	std::cout << std::get<0>(t4) << std::endl;

}
