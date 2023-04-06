// 143 
#include <functional>

int main()
{
	// 람다표현식을 담는 방법

	// 방법 1. auto 변수에 담기
	auto f1 = [](int a, int b) { return a + b; };

	// 방법 2. 함수 포인터에 담기
	int(*f2)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx();

	// 방법 3. std::function<> 에 담기
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// 아래 3줄을 생각해봅시다.
	f1(1, 2); 
	f1.operator()(1, 2);// 위 코드는 이코드와 동일
						// 함수를 직접 호출하므로 인라인 치환가능
	f2(1, 2);	// 호출 가능하지만, 인라인 치환은 안됨
	f3(1, 2);	// 호출 가능하지만, 인라인 치환은 안됨
}





