#include <iostream>

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
		std::cout << "임시객체가 아닌 경우" << std::endl;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		std::cout << "임시객체인 경우" << std::endl;
	//	name = c.name; // 포인터 복사

		c.name = nullptr;	// 이코드가 되려면
							// 임시객체(rvalue)를 상수성없이
							// 가리킬수 있어야 합니다.
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
	Cat c2 = c1;

	Cat c3 = foo(); // 이순간 메모리 그림을 생각해 보세요
					// 
}
