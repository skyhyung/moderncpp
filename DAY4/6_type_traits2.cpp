#include <iostream>
#include <type_traits>

template<typename T> void foo(const T& a)
{
	if ( ? )
		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}