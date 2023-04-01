// 8_nullptr2
#include <iostream>

// 왜 nullptr을 만들었나 ?
void foo(int)   { std::cout << "int" << std::endl; }
void foo(void*) { std::cout << "void*" << std::endl; }
void goo(char*) { std::cout << "goo" << std::endl; }

int main()
{
	foo(0);  // int
	foo(0);  // void*
}







