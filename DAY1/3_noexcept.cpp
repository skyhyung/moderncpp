// 3_noexcept - 14 page
#include <iostream>
#include <exception>

void foo() 
{
}
void goo()
{
	if (1) // ����
		throw std::bad_alloc();
}

int main()
{
}




