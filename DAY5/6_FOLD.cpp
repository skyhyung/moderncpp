// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : 가변인자 템플릿의 모든 요소에
//				이항 연산을 수행 - C++17

template<typename ... Types> 
int Sum(Types ... args)
{

}
int main()
{
	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << n << std::endl;
}



