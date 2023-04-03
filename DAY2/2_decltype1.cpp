#include <iostream>

int x = 0;

int  f1() { return x; }
int& f2() { return x; }

int main()
{
	f1() = 20;
}