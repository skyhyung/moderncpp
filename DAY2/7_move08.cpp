#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 1. 복사 계열과 move 계열을 모두 만들지 않으면
//    => 컴파일러가 모두 제공한다.
//    => copy 계열에서는 모든 멤버를 copy로 옮기고
//    => move 계열에서는 모든 멤버를 move로 옮긴다.
//    => 아주 좋은 결과!!!

// 규칙 2. 사용자가 복사 계열만 제공하면
//	=> 컴파일러는 MOVE 계열 함수 제공안함
//	=> std::move 사용시 복사 계열함수 호출됨.
//	=> 컴파일러에게 move 계열 함수 요청하려면 "= default" 사용

// 규칙 3. 사용자가 move 계열만 제공하면
// => 컴파일러가 copy 계열 제공안함(정확히는 =delete 해버림)
// => copy 가 필요한 함수를 사용하면 "컴파일 에러"
// => 필요하면 "=defaule"로 요청가능
struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 일반 생성자

	/*
	Object(const Object& other) :name(other.name)
	{
		std::cout << "user copy ctor" << std::endl;
	}

	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
	*/
	
	Object(Object&& other) :name(std::move(other.name))
	{
		std::cout << "user move ctor" << std::endl;
	}
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name() << std::endl;
	std::cout << o2.name() << std::endl;
}
