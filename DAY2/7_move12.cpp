#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// setter 를 만드는 최선의 방법을 찾아 봅시다.
	// 방법 1. call by value - 복사본 생성됨. 나쁜 코드
	//void set_name(std::string n) { name = n; }

	// 방법 2. const reference
	// C++98 시절은 좋은 코드였지만, C++11 부터는 약간 부족!!
//	void set_name(const std::string& n) { name = n; } // 항상문자열복사
//	void set_name(const std::string& n) { name = std::move(n); } 
							// 항상문자열복사. const 참조 이므로

	// 최선의 setter, 2개를 만들어라!
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








