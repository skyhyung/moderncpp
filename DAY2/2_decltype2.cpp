#include <complex>

int main()
{
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11. 일관된 초기화(uniform initialization)
	// => 모든 종류의 변수를 {}로 일관되게 초기화 가능
	// => 흔히, 중괄호(brace init) 초기화 라고도 합니다.
	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };

	int n3 { 10 };
	int x3[2] { 1,2 };
	std::complex<double> c3 { 1, 2 };

	// direct initialization : =이 없는 초기화
	// copy   initialization : =이 있는 초기화
}












