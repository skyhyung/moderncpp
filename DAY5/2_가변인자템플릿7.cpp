// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 가변인자 템플릿을 언제 사용하나요 ?
// => 가변인자 템플릿이 필요한 전형적인 코드가 있습니다.

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f( std::forward<Types>(args)...); 
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

