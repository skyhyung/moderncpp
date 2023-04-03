// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	std::string s1 = "\\\\.\\pipe\\server";

	// raw string : \ 를 일반 문자로 취급
	// 문자열 시작 : "(
	//        종료 : )"
//	std::string s2 = R"(\\.\pipe\server)";

	// " 표기하려면
//	std::string s2 = R"(\\.\pi"pe\server)";


	// 핵심 : )" 를 표기하려면
	std::string s2 = R"***(\\.\pi)"pe\server)***";


	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
