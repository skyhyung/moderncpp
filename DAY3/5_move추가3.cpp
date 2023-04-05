#include <iostream>
#include <string>
#include <vector>
#include <array>


class People
{
private:
	std::string name;
	std::string address;
public:
	// 생성자도 결국 setter 와 유사합니다
	/*
	People(const std::string& name, const std::string& addr)
		: name(name), address(addr)
	{
	}
	*/
	template<typename T1, typename T2>
	People(T1&& name, T2&& addr)
		: name(std::forward<T1>(name)), 
		  address(std::forward<T2>(addr))
	{
	}


	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
};



int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));
}








