#include <iostream>

template<typename T> void foo(T&& arg)
{
	// Ȯ���ϴ¹�
}
int main()
{
	int n = 10;

	foo(n);  //
	foo(10); //
}




