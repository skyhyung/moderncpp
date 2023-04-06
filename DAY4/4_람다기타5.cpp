#include <functional>

int add(int a, int b) { return a + b; }

class BigFO
{
	int x[32];
public:
	inline int operator()(int a, int b) // <== const 멤버 함수아님
	{ 
		x[0] = 10;
		return a + b; 
	}
};
// () 로 호출가능한것 : 일반함수, 함수객체, 람다표현식
// foo 을 만드는 최선의 코드를 생각해 봅시다.

// 방법 1. 함수 포인터
// => 일반 함수, 캡쳐되지 않은 람다는 전달 가능
// => 캡쳐한 람다, std::less<>, 함수 포인터 변환연산자가 없는 객체 안됨
// => 장점 : template 아님. 코드 증가 안됨.
// void foo( int(*f)(int, int) ) {}

// 방법 2. std::function
// => 아래 모든 경우를 다 받을수 있음.
// => 그런데 "f(1,2)" 등으로 사용시 인라인 치환 안됨.
// void foo(std::function<int(int, int)> f) {}

// 방법 3. 템플릿,  call by value
// => 함수와 함수객체, 람다는 대부분 크기가 작다. 
// => 하지만 크기가 큰 함수객체 라면 복사본의 오버헤드
// => 템플릿이므로 foo가 여러개 생성
//template<typename T> void foo(T f) {}

// 방법 4. 템플릿, call by reference
// => 람다 표현식은 "임시객체" 이다. 받을수 없다.
//template<typename T> void foo(T& f) {}


// 방법 5. call by const reference
// => operator() 가 반드시 상수 멤버 함수 이어야 한다.
// => mutable 람다를 받을수 없다.
template<typename T> void foo(const T& f) 
{
	f(1, 2); // f.operator()(1,2)
}

// 방법 6. forwarding reference
// => 모든 것을 참조로 받을수 있으므로 좋지만.... ???
template<typename T> void foo(T&& f)
{
}


int main()
{
	foo(&add);

	foo([](int a, int b) { return a + b; });

	int v1 = 10;
	foo([v1](int a, int b) { return a - b + v1; });

	foo(std::less<int>());

	BigFO f;
	foo(f);
}


// cpprefrence.com 에서 find_if 검색
