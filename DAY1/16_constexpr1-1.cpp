// 16_constexpr1-1

int main()
{
	int n = 10;

	const int c1 = n;	// ok
	const int c2 = 10;	// ok

	// C++11 의 constexpr 키워드는 "컴파일 시간" 을 의미
	constexpr int c3 = n;	// error
	constexpr int c4 = 10;	// ok

}
