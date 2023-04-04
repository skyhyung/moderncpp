// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// () 안에 심볼의 이름만 있으므로 규칙 1. 
	decltype(p)		d1;  // int* d1

	// 규칙 2. () 안에 "심볼의 이름과 연산자 등을 포함한 표현식이 있을때"
	// => 해당 표현식이 lvalue 라면 reference, 
	// => lvalue 가 아니면 value
	decltype(*p)	d2; // int& d2		초기값 없으므로 error
	decltype(x[0])	d3; // int& d3		초기값 없으므로 error

	auto a = x[0]; // int a = x[0]. auto 는 우변의 reference 를 제거	
					//				하고 결정하므로

	decltype(n) d;	// "n = 10" 처럼 등호의 왼쪽에 올수 있지만
					// 심볼의 이름만 있으므로 규칙 1. 적용
					// int d
			

	decltype(n + n) d4; // "n+n" 은 등호의 왼쪽에 올수 없다.
						// int d4

	decltype(++n)   d5; // "++n = 10"  가 가능하다.
						// int& d5		초기값 없어서 error
												
	decltype(n++)   d6; // "n++= 10" 은 에러!!
						// int d6
	
			
}

