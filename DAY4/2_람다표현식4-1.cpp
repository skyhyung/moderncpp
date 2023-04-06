// 2_람다표현식4-1  - 2번 복사.. 

#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 아래 코드에 대해서 생각해 봅시다.
	// sort() 함수가 몇개 생성되었을까요 ?
	// => 3개.!! 모든 람다표현식(동일한 코드라도)은 다른 타입이다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 위 코드보다 아래 코드가 더 좋습니다.
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// 아니면 less사용하세요
	// => 해당 기능이 이미 표준에 있다면 람다 표현식 대신 사용해도 
	//    좋습니다.
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});
}



