// 8_nullptr2
#include <iostream>

// �� nullptr�� ������� ?
void foo(int)   { std::cout << "int" << std::endl; }
void foo(void*) { std::cout << "void*" << std::endl; }
void goo(char*) { std::cout << "goo" << std::endl; }

int main()
{
	foo(0);  // int
	foo(0);  // void*
}







