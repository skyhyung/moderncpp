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
	
	// A class형이 T1으로 들어오게 되면 error 발생한다.
	// error를 막기 위한 방법은?
	/*
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
	*/
	
	// enable_if를 사용하면 T1으로 들어와서 자료형이 맞지 않다는 error는 나지 않는다.
	// 해당 자료형으로 overriding 된 함수가 없다고 error qkftod
	template<typename T1, typename T2>
	// is_same_v 은 같아야 하기 때문에 조건이 복잡해지고 안될 가능성이 크다.
	// std::enable_if_t< std::is_same_v<std::remove_cv_t<std::remove_reference_t<T1>>, std::string> > 

	// string으로 변환 가능하면 아래의 template를 쓰도록 하는 방법이 좋다.
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
	//p.set(aaa,  addr);  // aaa는 name으로 forwarding 되는데 aaa는 A class형이고 name은 string형 이다.

	std::pair<int, double> p2;

}
