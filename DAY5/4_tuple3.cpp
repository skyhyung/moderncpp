// Step2. 한개 요소 보관하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0; 
};

// 템플릿 인자가 한개 이상 있을때를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {} 

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
