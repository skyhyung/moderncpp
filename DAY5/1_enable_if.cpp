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
	/*
	// 아래 코드의 일때의 에러메세지와
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
	*/
	// 아래 코드의 에러메세지를 비교 해보세요
	template<typename T1, typename T2>
	
//	std::enable_if_t< std::is_same_v<std::remove_cv_t<std::remove_reference_t<T1>>, std::string> > 
	
	std::enable_if_t< std::is_convertible_v< T1, std::string> &&
					  std::is_convertible_v< T2, std::string> >
	set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}

};




class A {};

int main()
{
	A aaa;

	const std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name, addr);
	p.set("lee", addr);
//	p.set(aaa,  addr);

}
