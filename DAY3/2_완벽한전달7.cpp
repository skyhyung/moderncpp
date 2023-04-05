#include <iostream>

void f0() {}
void f1(int a) {}
void f3(int a, double d, int& r) { r = 300; }

int& f4(int& a) { return a; }

// 완벽한 전달 코딩 관례
// 1. 인자의 갯수 제한을 없애기 위해서 "가변인자 템플릿" 사용
// 2. 반환타입도 완벽히 돌려주기 위해 "decltype(auto)" 사용

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg) 
{
	// StopWatch sw; // 생성자에서 시간 기록하세요
					 // 소멸자는 아래 함수 호출후에 호출됩니다.
					 // 소멸자에서 수행시간 출력하면 됩니다.
	return f(std::forward<T>(arg)... );
}

int main()
{
	int n = 0;
	chronometry(f0);
	chronometry(f1, 10);
	chronometry(f3, 10, 3.4, n);

	std::cout << n << std::endl; // 200

	int& ret = chronometry(f4, n); // f4(n)
	ret = 20;

	std::cout << n << std::endl; // 20
}
