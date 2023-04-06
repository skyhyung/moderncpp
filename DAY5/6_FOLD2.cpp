#include <iostream>

template<typename ... Types>
void Show(Types ... args)
{
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



