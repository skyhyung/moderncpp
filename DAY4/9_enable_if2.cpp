#include <iostream>
#include <type_traits>


// 다양한 크기의 정수에 적용하기 위한 최대 공약수 템플릿 gcd
template<typename T> T gcd(T a, T b)
{
	// static_assert : 조건을 만족하지 못하면 무조건 에러 !!
	// 조건을 만족하지 못할때 에러가 아닌 후보에서 제외 될수 없을까 ?
	static_assert(std::is_integral_v<T>, "error. not integer");

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
	gcd(3.1,  5.4);
	gcd(3.1f, 5.4f);
}





