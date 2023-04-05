int main()
{
	int n = 10;

	// 다음중 에러를 "모두" 찾으세요

	auto&  r1 = n;  // ok
	auto&  r2 = 10; // error
	auto&& r3 = n;  // ok. int& r3 = n
	auto&& r4 = 10; // ok. int&& r4 = 10

	auto a = 10;
	// T a = 인자;
}
