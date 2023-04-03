// 8_nullptr2-1
#include <iostream>

void foo(int* p) {}


int main()
{
	int n = 0;
	foo(0); // ?
	foo(n); // ?
}







