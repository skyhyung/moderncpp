// 17_static_if - 51 page

// 아래 코드는 에러가 있을까요 ?
template<typename T> void foo(T a)
{
//	if (false)
//		*a = 10;

	// 컴파일 시간 if 문 - C++17 문법
	// => 조건식은 컴파일 시간에 조사 가능해야 한다.
	// => 조건식이 false 라면
	// => 인스턴스화("템플릿 => 실제함수생성")에 포함 안됨
	if constexpr (false)
		*a = 10;

}
int main()
{
	foo(0); 
}

