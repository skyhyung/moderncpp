// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");
	foo("hello");
				
}


