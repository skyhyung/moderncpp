// 교재 5 page
#include <cassert>

// static_assert
// => 컴파일 시간 assert
// => 함수 안 또는 밖에 있어도 됩니다.
// => 표현식은 반드시 컴파일 시간에 조사 가능해야 합니다.
//    static_assert(age > 0, "error"); // 이 표현식은 안됨!

static_assert(sizeof(int*) >= 8, "error not 64bit");

void foo(int age)
{
	// 함수 인자는 사용하기 전에 유효성을 확인하는 것이 좋다
	assert(age > 0); // 실행시간 표현식의 유효성 조사

//	static_assert(sizeof(int*) >= 8, "error not 64bit");



	int* p = new int[age];

	delete[] p;
}

int main()
{
//	foo(10);
	foo(-10);
}




