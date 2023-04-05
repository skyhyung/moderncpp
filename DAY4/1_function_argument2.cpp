#include <string>
#include <string_view> // C++17 사용할수 있게 설정필요

int main()
{
	std::string s = "to be or not to be";

	std::string s1 = s; 	   // s의 문자열을 s1으로 복사. string은 문자열을 소유한다.
	std::string_view sv = s;   // sv는 s가 가지고 있는 문자열을 보기만한다. 
				   // 문자열을 소유하지 않는다. (자원을 소유하지 않는다)
				   // 그러므로 크기가 작다.
}
