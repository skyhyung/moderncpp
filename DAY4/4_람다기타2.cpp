// 함수 인자로 auto ??
// => error. 
// => 단, C++20 부터 가능
//void foo(auto n) {} 

int main()
{
//	foo(3);
//	foo(3.4);


	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // 결국 3 + 3 이므로 데이타 손실

	// generic lambda
	// => C++14 부터 람다 표현식 인자로 auto 사용가능
	auto add = [](auto a, auto b) { return a + b; };
	
	std::cout << add(1,   2) << std::endl;
	std::cout << add(1.1, 2.1) << std::endl;
	std::cout << add(1,   2.1) << std::endl;
	std::cout << add(1.1, 2) << std::endl;
}

// generic 람다의 원리
// => auto 인자를 template 으로 변경
// => 2개의 인자가 서로 다른 템플릿 인자
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
