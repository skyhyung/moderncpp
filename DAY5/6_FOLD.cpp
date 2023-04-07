// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : 가변인자 템플릿의 모든 요소에
//				이항 연산을 수행 - C++17
// => 반드시 ()가 있어야 합니다.

template<typename ... Types> 
int Sum(Types ... args)
{
        //int s = (args + ...);         // unary right 
					// ( E1 + (E2 + (E3 + E4)))

        //int s = (... + args);	        // unary left
					// ((((E1 + E2) + E3) + E4 )

        //int s = (args + ... + 0);     // binary right - 초기값 추가 가능
					// ( E1 + (E2 + (E3 + (E4 + 0)))

	int s = (0 + ... + args);	// binary left
					// (((( 0 + E1) + E2) + E3) + E4 )

	return s;
}
int main()
{
	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << n << std::endl;
}
