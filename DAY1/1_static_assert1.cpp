#include <cassert>

void foo(int age)
{
	int* p = new int[age];

	delete[] p;
}
int main()
{
	foo(10);
}