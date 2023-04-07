#include <iostream>

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};

template<int N, typename T>
struct tuple_element;


// N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;    
	using tupleType = tuple<T, Types...>; 
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...>>::type;

	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};




template<int N, typename TP>
typename tuple_element<N, TP>::type&
get(TP& t)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(t).value;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	get<1>(t) = 9.9;

	std::cout << get<1>(t) << std::endl; // 9.9
}
