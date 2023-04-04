#include <iostream>

// rule of 5, 3

// rule of 3 : 클래스가 자원을 할당하면 3개의 함수를 추가적으로 만들어야한다
// => 소멸자, 복사 생성자, 대입연산자

// rule of 5 : C++11 부터는 되도록 2개를 더 만들어라
// => move 생성자, move 대입 연산자

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
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
	// 대입연산자
	Cat& operator=(const Cat& c)
	{
		// c = c 처럼 자신과의 대입을 고려한 코드
		if (&c == this) return *this;

		age = c.age;
		delete[] name;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this; // 대입연산자는 자신을 참조로 반환하는규칙이 있습니다
	}

	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
	}
};




int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// 복사 생성자 호출, c2를 만들면서 초기화
	c2 = c1;		// 대입 연산자 호출. c2.operator=(c1)

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




