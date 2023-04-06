// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	Test::data  * p;   // 0 * 전역변수p 이므로 * 는 "곱하기"
	Test::DWORD * p;	// int* p 의 의미, 즉,* 는 "포인터 연산자"

	// "클래스이름::이름" 에서 "이름"의 의미는
	// 1. 값 이거나   : static 멤버 데이타, enum 상수등
	// 2. 타입 일수 있습니다.

	// 의존이름(dependent name )
	// => 템플릿 인자 T에 의존한 이름
	// => 컴파일러는 항상 값으로 해석합니다.
	// => 타입의 이름으로 해석되게 하려면 "typename" 을 붙여야 합니다.
//	T::data * p2;	// error. p2는 없다
//	T::DWORD* p2;	// error. DWORD 를 값으로 해석하기 때문에..

	typename T::DWORD* p2; // ok. DWORD를타입의 이름으로 
							// 해석해 달라는 것
}


int main()
{
	Test t;
	foo(t);
}



