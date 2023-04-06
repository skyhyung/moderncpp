#include <iostream>
#include <type_traits>

template<typename T> 
std::enable_if_t< std::is_pointer_v<T> > 
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}
//반대 되는 enable_if 가 없으면 둘다 타게 된다...? 확인 해보자
template<typename T> 
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n); 
	printv(&n); 
}

