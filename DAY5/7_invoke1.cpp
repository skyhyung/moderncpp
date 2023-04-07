#include <functional>

class Object
{
public:
	void func1(int code) {}
	static void func2(int code) {}
};
void foo(int n) {}

int main()
{
	// 핵심 1. 일반 함수 포인터에 non-static 멤버 함수의 주소를 담을수 없다
	void(*f1)(int) = &foo;			// ok
//	void(*f2)(int) = &Object::func1;	// error. 멤버 함수 이므로
									//		this가 추가되는 함수
	void(*f3)(int) = &Object::func2;	// ok. static 은 this 추가 안됨.


	// 핵심 2. 멤버 함수의 주소를 담는 방법
	void(Object::*f2)(int) = &Object::func1;


	// 핵심 3. 멤버 함수포인터를 사용해서 함수 를 호출하는 방법

//	f2(10); // error. 객체가 없다.   "객체.func2(10)"이어야한다.

	Object obj;
//	obj.f2(10); // error. obj 안에는 f2 라는 멤버는 없다.


	// 이때 필요한 것인 "pointer to member operator(.*)" 입니다.
	// obj.*f2(10); // error. 연산자 우선순위 문제

	(obj.*f2)(10); // ok...  !! obj.func2(10) 의 의미


	// 핵심 4. 모든 호출가능한 것을 동일하게 호출할수 없을까?
	
	f1(10);        // 일반 함수 포인터로 호출하는 모양
	(obj.*f2)(10); // 멤버 함수 포인터로 호출하는 모양

	// C++17 std::invoke
	std::invoke(f1, 10);
	std::invoke(f2, &obj, 10);
}




