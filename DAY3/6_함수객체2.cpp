#include <iostream>

// 핵심 : 함수는 "동작"은 있지만 "상태" 가 없다.
// => 함수 실행중에 생성된 데이타를 저장할 공간이 없다.
// => 그래서, 전역변수등을 사용하지만 좋은 코드는 아니다.

// 0 ~9 사이의 "중복되지않은" 난수를 반환하는 함수
int urand()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}
