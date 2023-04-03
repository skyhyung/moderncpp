// 20_타입추론5

template<typename T> void foo(T a) {} // T a = 10

int main()
{
	// 템플릿 : 전달한 함수 인자로 타입 추론
	// auto   : 우변의 표현식으로 추론
	foo(10);
	//T  a = 함수인자(10);
	auto a = 10;

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// "T a" 즉, 값이므로, 규칙 1번 적용 => 우변의 const, volatile, reference 
	//									  모두 제거후 결정
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int
	
	// "T& a" 이므로 규칙 2. 우변의 레퍼런스만 제거, const, volatile유지
	auto& a5 = n; // auto : int   a5 : int&
	auto& a6 = r; // auto : int   a6 : int&
	auto& a7 = c; // auto : const int  a7 : const int&
	auto& a8 = cr;// auto : const int  a8 : const int&

//	a7 = 20; // error

	// 타입 추론과 배열
	int x[3] = { 1,2,3 };

	auto a1 = x;	// 1. int a1[3] = x; 로 결정하면 컴파일 에러
					// 2. int* a1 = x;  => 그래서 이렇게 결정
					// auto : int*
					// a1   : int*

	auto& a2 = x; // int (&a2)[3] = x; // 이렇게 결정
					// auto : int[3]
					// a2   : int(&)[3]
}


