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
//---------------------------------------------------------

template<typename T> void foo(T& tp)
{
	typename tuple_element<0, T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');
}
