#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	// read 와 retain 을 구별하세요
	// read   : move 고려할 필여 없습니다.
	// retain : move 고려해야 합니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
	// std::array 는 동적할당하지 않습니다.
	// move고려할필요 없습니다.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.set_data(arr);


	std::vector<std::string> v;
	v.push_back(s);
	v.push_back(std::move(s));
}








