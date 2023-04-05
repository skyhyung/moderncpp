#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int&& r2 = 10;
	foo(r2);	// int&,   r2는  lvalue 이므로
	foo(static_cast<int&&>(r2));// int&&,  
							// lvalue인 r2를 rvalue로 캐스팅
}







