#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class Object
{
private:
	std::string name;
public:
	// #1. 인자가 non-const lvalue reference 인경우
	void foo(std::string& s)
	{

	}

	// #2. 인자가 const reference 인 경우
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// #3. 전달 받은 인자의 값을 함수에서만 사용하는 것이 아니라
	//     멤버 데이타등에 보관하는 경우.
	void set_name(const std::string& n) { name = n; }
};

int main()
{
	std::string s = "park";

	Object p;
	p.print_msg(s);
}








