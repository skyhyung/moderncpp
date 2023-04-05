#include <string>
#include <string_view> // C++17 사용할수 있게 설정필요

int main()
{
	std::string s = "to be or not to be";

	std::string s1 = s;
	std::string_view sv = s;  
}
