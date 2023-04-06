#include <string>
#include <string_view> // C++17 사용할수 있게 설정필요

#include <iostream>
void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}


void f1(const std::string& s) {}

void f2(std::string_view   s) {}

int main()
{
//	std::string s = "to be or not to be";

	// 아래 2개를 비교해 봅시다.
	// => 아래 2줄은 성능이 거의 유사합니다.
//	f1(s);
//	f2(s);

	// 그런데.. 아래 2줄을 생각해 보세요
	f1("to be or not to be");	// string 의 임시객체를 만들게 되고
								// 메모리를 동적할당해서 문자열 보관 -> static 공간(?)에 있는 string을 소유
								// new 사용
	f2("to be or not to be");	// new 사용하지 않음. static 공간(?)에 있는 string 참조.
}




