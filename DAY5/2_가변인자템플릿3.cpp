#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{

}


int main()
{
	foo(1, 2, 3);
}
