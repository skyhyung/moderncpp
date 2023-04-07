#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면

	// args 안에서 2번째 값을 꺼내고 싶다 => 한번에 하는 방법은 없습니다.

	// 아래 3개중에 한개를 사용해야 합니다.
	// 1. pack expansion 을 사용하거나
	// 2. recursive 를 사용하거나
	// 3. fold expression - C++17 

	// Pack Expansion
	// 1. 요소의 타입이 동일하면 배열에 담아서 사용하세요
	int x[] = { args... };


	// 2. 요소의 타입이 다르면 tuple 에 담아서 사용하세요
	std::tuple<Types...> t(args...);

	std::cout << std::get<0>(t) << std::endl;
	std::cout << std::get<1>(t) << std::endl;


}


int main()
{
	foo(1, 2, 3);
}

