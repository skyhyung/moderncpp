// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type




int main()
{
	remove_pointer<int*>::type n2; 
}

template<typename T> void foo(T a)
{
}