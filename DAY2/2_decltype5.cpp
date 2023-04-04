int main()
{
	int x[3] = { 1,2,3 };

	
	auto a = x[0];		// int a = x[0];

	decltype(x[0]) d;   // int& d;   초기값 문제로 erro


	// 배열과 타입 추론
	auto a1 = x;		// int* a1 = x

	decltype(x) d1;		// int d1[3];
}

