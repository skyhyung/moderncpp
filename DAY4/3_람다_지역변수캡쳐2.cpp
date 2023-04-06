// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 아래 람다 표현식의 "operator()" 는 상수 멤버 함수 입니다.
//	auto f = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// 아래 람다 표현식의 "operator()" 는 상수 멤버 함수가 아닙니다.
	auto f = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	f(0); // v1 = 100 이 실행되지만 main 의 v1이 아닙니다.

	std::cout << v1 << std::endl; // 10

	std::cout << sizeof(f) << std::endl; //  8



	//-----------------------
	// 위 코드를 보고 컴파일러가 만드는 코드는 아래 코드 입니다.
	class CompilerGeneratedName
	{
		int v1;	// 지역변수를 캡쳐하면 멤버 데이타가 추가 됩니다.
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) 	// const 위의 mutable keyword는 기본적으로 삽입되는 const를 제거해 달라는 말.
		{				// const 가 있으면 상수 멤버 함수이고 
			v1 = 100; 		// 상수 멤버 함수는 멤버 변수를 변경시키지 않는 멤버 함수를 나타낸다 ,상수 객체는 상수 함수만 부를 수 있기 때문이다.
			return a + v1 + v2;	// 사용하는 이유는 상수 객체는 상수 멤버 함수만 부를 수 있기 때문이다.
		}				// const Point pt(1, 2); 
	};					// pt.print <- 여기서 print는 상수 멤버 함수라고 가정. 
	auto f = CompilerGeneratedName(v1, v2); // <= 여기서 v1, v2는 
											//    main 함수 지역변수!

}





