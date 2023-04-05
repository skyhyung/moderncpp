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
	// move 지원 setter 만들기
	// 방법 1. 2개의 setter.. 
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// 방법 2. 
};

int main()
{
	std::string s = "park";

	Object p;
	p.set_name(s);
	p.set_name(std::move(s));
}








