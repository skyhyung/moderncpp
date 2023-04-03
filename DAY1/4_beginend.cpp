// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// C++98 스타일의 반복자 꺼내기
	// 반복자 타입이름을 직접 사용하면
	// 1. 복잡하다.
	// 2. 컨테이너 변경시 반복자 타입 이름도 변경해야 한다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// C++11 부터는 auto 가 좋습니다.
//	auto p1 = v.begin();
//	auto p2 = v.end();

	// 멤버 함수 begin 보다 일반 함수 begin 이 유연성이 좋다.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);   // 배열도 가능.

//	auto sz1 = v.size();	 // v가 배열이면 에러
	auto sz1 = std::size(v); // v가 배열이라도 ok.


	// C++20 스타일
//	auto p3 = std::range::begin(v); // <== C++20 부터는 강력권장(안전)

	// 기존 begin 의 문제점
//	auto p4 = std::begin( std::vector<int>{1, 2, 3} ); // ok
}





// std::begin 의 원리

// 컨테이너 버전
template<typename T>
auto begin(T& c) { return c.begin(); } // 결국 멤버 함수 호출

// 배열 버전
template<typename T, int N>
auto begin(T(&arr)[N]) { return arr; } // 배열의 이름(주소)반환
auto end(T(&arr)[N])  { return arr+N; } 

