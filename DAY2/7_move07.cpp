// 6번 복사. move 계열함수 에서는 모든 멤버를 move로 옮겨라!
#include <iostream>
#include <string>

class Cat
{
	char* name;
	int   age;
	std::string address;
public:
	Cat(const char* n, int a, const std::string& s = "unknown")
		: age(a), address(s)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age), address(c.address)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c)
		//: age(c.age), name(c.name), address(c.address)
		: age(c.age), name(c.name), address(std::move(c.address))
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		address = c.address;
		age = c.age;
		delete[] name;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		address = std::move(c.address);

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
	Cat c2 = c1;	
	c2 = c1;		

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}





