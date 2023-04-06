#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
};

int main()
{
	Point buff1[10];
	Point buff2[10];

	copy_type(buff1, buff2, 10);
}
