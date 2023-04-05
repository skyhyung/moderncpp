#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

class IsDivide
{
	int value;
public:
	IsDivide(int n) : value(n) {}

	bool operator()(int n)
	{
		return n % value == 0; 
	}
};
int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 5;
	
//	IsDivde f(k);
//	auto p1 = std::find_if(v.begin(), v.end(), f);
	auto p1 = std::find_if(v.begin(), v.end(), IsDivide(k) );

}

// 일급 객체(first class object)
// => 함수 인자로 전달가능하고, 반환 값으로 사용가능한 객체
// => "함수" 도  다른 함수에 인자로 전달가능하므로 일급객체

// 클로져
// => 문맥에 포함된 지역변수를 캡쳐할수 있는 일급객체

// 일반함수 : 일급객체지만 클로져는 아님
// 함수객체 : 일급객체이고 클로져이기도 하다


