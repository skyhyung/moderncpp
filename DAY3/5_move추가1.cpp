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
	// => 함수안에서 s 를 변경하겠다는 것 ( R/W )
	void foo(std::string& s)
	{

	}

	// #2. 인자가 const lvalue reference 인 경우
	// =>함수 안에서 인자를 읽기만 하겠다 ( R )
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}


	// #3. 전달 받은 인자의 값을 함수에서만 사용하는 것이 아니라
	//     멤버 데이타등에 보관하는 경우.
	// => move 를 지원하기 위해서 2개를 만드세요
	void set_name(const std::string& n)  {	name = n; 	}
	void set_name(std::string&& n) { name = std::move(n); }

	// 결국 인자가 "std::string&&" 의 의도는 move 입니다

	// 아래 함수를 생각해 봅시다.
	// => 타입&& 이므로 move의 의도일텐데..
	// => const 이므로 move 될수 없습니다.
	void foo(const std::string&& s) {} 
};

int main()
{
	std::string s = "park";

	Object p;
	p.set_name(s);
	p.set_name(std::move(s));
}








