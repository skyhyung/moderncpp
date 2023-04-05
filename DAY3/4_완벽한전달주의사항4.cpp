int main()
{
	int n = 10;

	// 다음중 에러를 "모두" 찾으세요

	auto&  r1 = n;
	auto&  r2 = 10;
	auto&& r3 = n;
	auto&& r4 = 10;
}
