#include <iostream>
#include <type_traits> 

struct PACKET
{
	char cmd;
	int  data;
};

int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}

template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}
