// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // C++ 표준이 제공하는 리터럴 접미사!

void foo(const char* s) { std::cout << "char*"; }	// 1	
void foo(std::string s) { std::cout << "string"; }  // 2

int main()
{
	foo("hello");  // 1
	foo("hello"s); // 2.  std::string operator""s("hello")
	
//	std::this_thread::sleep_for( 3 ); // error

	std::this_thread::sleep_for( std::chrono::seconds(3) ); // ok
	std::this_thread::sleep_for( 3s ); // 위와 동일

	std::chrono::seconds s1 = 1h + 3min + 3s;

	std::cout << s1.count() << std::endl; // 3783

}


