class Meter
{
	int value;
public:
	Meter(int n) :value(n) {}
};

Meter operator""_m(unsigned long long n)
{
	Meter meter( static_cast<int>(n) );
	return meter;
}
int main()
{
	double d = 3.4;
	float f = 3.4f;
	   
	// 아래 처럼 사용할수 있으면 좋지 않을까?
	Meter me = 10_m;		// 이순간 문법적으로 약속된 함수 검색
						// operator""m(10)
//	Gram  b  = 10gram;

	// 참고. rust 언어 코드 입니다.
//	let b1 = 10_i32;
}




