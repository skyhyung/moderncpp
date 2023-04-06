// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	auto f = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	//-----------------------
	// 위 코드를 보고 컴파일러가 만드는 코드는 아래 코드 입니다.
	class CompilerGeneratedName
	{
		int v1;	// 지역변수를 캡쳐하면 멤버 데이타가 추가 됩니다.
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100; 
			return a + v1 + v2;
		}
	};
	auto f = CompilerGeneratedName(v1, v2); // <= 여기서 v1, v2는 
											//    main 함수 지역변수!

}





