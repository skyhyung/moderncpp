// std::move()소개
#include <iostream>
#include <cstring>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;		// 복사
	Cat c3 = foo();		// 이동
	Cat c4 = static_cast<Cat&&>(c2); // 이동
	Cat c5 = std::move(c3); // move 가 내부적으로 위 처럼 캐스팅
							// 합니다.

	// 결론
	// 1. std::move 가 자원을 이동하는 것 아닙니다.
	// 2. std::move는 객체를 rvalue로 캐스팅만 하고
	// 3. 캐스팅 결과로 복사 생성자가 아닌 이동생성자 호출
	// 4. 실제 자원을 이동하는 것은 Cat 의 설계자가 만든 이동생성자
}




