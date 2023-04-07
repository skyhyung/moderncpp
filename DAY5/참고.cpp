#include <iostream>

template<typename ... Types> struct first_type_impl;

template<typename T, typename ... Types> struct first_type_impl<T, Types...>
{
	using type = T;
};

template<typename ... Types> 
using first_type = typename first_type_impl<Types...>::type;

//-----------------------------------------------------------------------
template<typename ... Types> void foo(Types ... args)
{
	auto x[] = { args... }; // error. 

	first_type<Types...> x[] = { args... };	// 이렇게 하면 1번째 인자의 타입을 결정해서 배열사용가능

	std::cout << typeid(x[0]).name() << std::endl;
}

int main()
{
	foo(1, 2, 3, 4);
}
