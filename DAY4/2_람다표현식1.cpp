// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// sort 하고 싶다면
	// 방법 1. 비교 정책 생략 - 오름 차순으로 정렬
	std::sort(v.begin(), v.end());

	// 방법 2. 비교정책 전달 - 일반 함수 사용
	// => 일반함수를 사용하면 비교 정책 함수의 인라인 치환은 안됨
	std::sort(v.begin(), v.end(), cmp);

	// 방법 3. 함수객체 전달 - 비교 정책이 인라인 치환
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>() ); // C++98
	std::sort(v.begin(), v.end(), std::less<int>{} ); // C++11
	std::sort(v.begin(), v.end(), std::less{}); // C++17 부터 타입생략가능. 위에 3개다 같은 거임


	// 방법 4. 람다표현식 사용 - c++11 부터 가능
	// 람다 표현식
	// => 익명의 함수를 만드는 문법
	// [] : 람다가 시작됨을 알리는 기호(lambda introducer)
	// 상황에 따라 람다가 좋을 수도 있고 less가 좋을 수도 있다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}





