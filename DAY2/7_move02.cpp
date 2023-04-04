#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

template<typename T>
void Swap(T& a, T& b)
{
	// 아래 코드는 복사에 의한 swap 입니다.
	// => 성능이 좋지 않습니다
	T tmp = a;
	a = b;
	b = tmp;
}
// C++ 표준의 swap 이 아래 처럼 move로 되어 있습니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move 에서 알아야 하는 점
// 1. swap 등의 알고리즘 작성시 적절히 move를 사용하면 빨라집니다.
// 
// 2. string 이 아닌 사용자 타입이 move를 지원하려면 어떻게 해야 하는가 ?

