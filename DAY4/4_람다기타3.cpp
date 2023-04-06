int main()
{
	// 람다로 swap 을 만들어 봅시다.

	// 방법 1. int 타입만 가능
	auto swap1 = [](int& a, int& b) { int tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	// 방법 2. generic 람다 - 모든 타입 가능
	auto swap2 = [](auto& a, auto& b) { int tmp = std::move(a);
										a = std::move(b);
										b = std::move(tmp); };
	int n = 10;
	double d = 3.4;

	swap2(n, d); // 되는게 좋을까요 ? 안되야 할까요 ?- 안되야합니다.
				// 그런데, 에러가 아닙니다.
				// 2개의 인자가 서로 다른 템플릿 이므로!!

	// 방법 3. template 람다
	// => 2개의 인자가 동일 타입이어야 한다는 조건을 표기할수 있다.
	// => C++20
	auto swap2 = []<typename T>(T& a, T& b) { int tmp = std::move(a);
										a = std::move(b);
										b = std::move(tmp); };

}








