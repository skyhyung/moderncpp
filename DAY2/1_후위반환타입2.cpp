// 후위반환 - 73 page 아래 부분
#include <iostream>

template<typename T1, typename T2>
//decltype(a*b) Mul(T1 a, T2 b) // error. a, b를 선언전에 사용

auto Mul(T1 a, T2 b) -> decltype(a* b) // ok.. 
{
	return a * b;
}

// C++14 부터 리턴 타입 생략도 가능합니다
// => 그런데, 이경우는 return 문장이 한개 일때만 가능합니다.
// => 위 코드는 return 타입을 명시 했으므로 return 문장이 여러개 라도 가능
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;

//	a = 20;	// error. 선언전에 사용
//	int a = 0;
//	a = 10; // ok. 선언후에 사용
}

