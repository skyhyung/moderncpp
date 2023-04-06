// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// capture by value : v1, v2 의 복사본 사용
//	auto f = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// capture by reference : v1, v2에 대한 참조를 보관
	auto f = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f(0); // v1 = 100 인데.. main 의 v1이 변경됩니다.
	std::cout << v1 << std::endl; // 100

	std::cout << sizeof(f) << std::endl; // 8또는 16
									// 참조또는 포인터 2개 크기		
									// 컴파일러마다 다를수 있음.


	//-----------------------

	class CompilerGeneratedName
	{
		int& v1;	// 컴파일러에 구현에따라 포인터로 보관할수도 있습니다.
		int& v2;	// 
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100;	// 이 코드는 v1 자체의 변경이 아닌
						// v1이 가리키는 곳을 변경하므로
						// "상수 멤버 함수라도 에러 아님"

			return a + v1 + v2;
		}
	};
	auto f = CompilerGeneratedName(v1, v2); 

}





