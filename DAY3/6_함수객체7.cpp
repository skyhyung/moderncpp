#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 모든 인자가 템플릿 입니다.

	// 1. 비교 정책으로 일반함수 사용시

	// 장점 : 비교 정책을 여러번 교체 해도 sort() 함수는 한개만 생성된다.
	//        코드메모리 증가하지 않는다.

	// 단점 : 비교정책 함수가 인라인 치환될수 없다. 
	//        인라인 치환보다는 느리다.

	std::sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int,int))인 함수 생성
	std::sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int,int))인 함수 생성


	// 2. 비교 정책으로 함수객체 사용시
	// 장점 : 비교정책이 인라인 치환된다. 빠르다!
	
	// 단점 : 정책을 교체한 횟수 만큼의 sort() 함수 생성
	//		 코드 메모리 증가

	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1); // sort(int*, int*, Less) 모양의 함수 생성
	std::sort(x, x + 10, f2); // sort(int*, int*, Greater) 모양의 함수 생성
}





