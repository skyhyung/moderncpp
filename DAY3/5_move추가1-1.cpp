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
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }

	// 방법 2. forwarding reference 를 사용하면 위 2개 자동생성 가능
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
		name = n;					// 1
		name = std::move(n);		// 2
		name = std::forward<T>(n);  // 3
	}
};

int main()
{
	std::string s = "park";

	Object p;
	p.set_name(s);
	p.set_name(std::move(s));
}








