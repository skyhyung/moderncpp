#include <iostream>
#include <type_traits>

// C++20 의 concept 문법
template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}

/*
void printv(std::is_pointer auto v)
{
	std::cout << v << std::endl;
}
*/

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

