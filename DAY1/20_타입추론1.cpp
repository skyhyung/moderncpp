// 20_타입추론1 - 69 page
// 타입 추론 문법

int main()
{
	auto a = 10;
	int x[3] = { 1,2,3 };

	// 우변의 표현식으로 좌변의 타입을 결정해 달라.
	// => 컴파일 시간에 결정, 실행시간 오버헤드 없음
	auto n = x[0];

	// decltype : () 안의 표현식의 타입을 조사해 달라.
	decltype(n) d;   // int d

	//================
	const int c = 10;

	auto a = c; // 1. const int ?
				// 2. int ? => 정답!

	// 타입 추론(type deduction) 
	// => 컴파일러가 타입을 결정하는 원리

	// 1. 템플릿
	// 2. auto
	// 3. decltype

	// 1,2번의 원리는 동일


}
