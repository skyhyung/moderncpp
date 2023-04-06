#include <iostream>
#include <type_traits>

// remove_pointer : * 를 한개 제거 합니다(C++ 표준도 동일!)

// 모든 * 를 제거해 봅시다.(C++ 표준에는 없습니다.)
template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = typename remove_all_pointer<T>::type;
};

int main()
{
	remove_all_pointer<int***>::type n;

	std::cout << typeid(n).name() << std::endl;
}
