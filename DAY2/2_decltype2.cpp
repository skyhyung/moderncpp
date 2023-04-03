// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// 규칙 1. () 안에 심볼의 이름만 있는 경우
	// => 심볼의 선언을 보고, 타입을 결정

	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2		초기값 없으므로 error
	decltype(c) d3; // const int d3 초기값 없으므로 error 
	decltype(p) d4; // int* d4

	auto a = c;			// int a = c
	decltype(c) d = c;	// const int d = c;
}
