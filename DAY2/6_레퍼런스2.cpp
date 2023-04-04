#include <iostream>

// 90 page

void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// 1번 사용. 없으면 2번 호출
	foo(10);	// 3번 사용. 없으면 2번 호출

	int& r1 = n;
	foo(r1);	// 1번 사용. 없으면 2번 호출


	int&& r2 = 10;	// 10은 rvalue 지만, r2는 이름이 있고
					// 단일식을 넘어 사용가능. lvalue
	foo(r2);	// 1번 사용. 

	//			타입			value 속성
	// 10		int			rvalue
	// n		int			lvalue
	// r2		int&&		lvalue

	// foo(int&) : 인자로 int& 타입을 받는것이 아니라
	//				int 형 lvalue 를 받겠다는것
	// foo(int&&): 인자로 int&& 타입을 받는것이 아니라
	//				int 형 rvalue 를 받겠다는것

	foo(r2); // r2는 lvalue 이므로 1번

	foo(static_cast<int&&>(r2)); // 3번
				// => r2가 int&& 타입인데.. 다시 int&& 로 캐스팅하네요 ??
				//	  같은 타입 아닌가요 ?
				// => "int&&" 로 캐스팅하는 것은 타입캐스팅이 아니라
				//    value 속성을 변경하는 캐스팅입니다.(C++표준문서)
				//    cppreference.com 참고
}







