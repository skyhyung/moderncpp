#include <iostream>
#include <type_traits>


// std::enable_if<true,  int>::type  => int
// std::enable_if<false, int>::type  => "::type" 이 없다

// enable_if 를 사용한 리턴타입 만들기 기술
// 
// std::enable_if<조건, 반환타입>::type
// => 조건이 참이면 반환타입 사용
// => 조건이 거짓이면 사용안함(에러가 아닌 후보에서 제외)

template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type

std::enable_if_t< std::is_integral_v<T>, T>
gcd(T a, T b)
{
	return 0;
}


double gcd(double, double)
{
	std::cout << "double" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}





