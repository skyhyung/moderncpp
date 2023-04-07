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
// 결국, primary template 이 사용되는 일이 없습니다.
// => 이럴때는 선언만 해도 됩니다.
// => 선언은 반드시 있어야 부분 특수화 가능합니다.
template<int N, typename T> 
struct tuple_element;


// N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T ;    // 0번째 요소의 타입
	using tupleType = tuple<T, Types...>; // 0번째를 보관하는 튜플타입
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...>>::type;

	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};


template<typename T> void foo(T& tp)
{
	// T : tuple<int, double, char>
	typename tuple_element<0, T>::type n; // int
	std::cout << typeid(n).name() << std::endl;

	typename tuple_element<1, T>::tupleType t;
	std::cout << typeid(t).name() << std::endl;

}



int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	foo(t);
}
