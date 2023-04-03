// 8_nullptr2-2.cpp
#include <iostream>

void f1(int* p) {}
void f2(char* p) {}

// nullptr 을 만들어 봅시다.
struct nullptr_t
{
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr);
	f2(mynullptr);
}
