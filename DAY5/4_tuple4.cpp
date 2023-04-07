// Step3. 모든 요소 보관하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

// 템플릿 인자가 한개 이상 있을때를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args) 
		: value(v), base( args...)  {}

	static constexpr int N = base::N + 1;
};



int main()
{
//	tuple<> t0;						// 보관 안함, primary 버전사용
//	tuple<             short> t1;	// short 보관 
//	tuple<     double, short> t2;	// double 보관
//	tuple<int, double, short> t3;	// int 보관

	tuple<int, double, short> t(1, 3.4, 2);
}
