// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 람다 표현식의 원리
	// => 위 한줄을 보고 컴파일러가 아래코드를 생성합니다

	class CompilerGeneratedName
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

}





