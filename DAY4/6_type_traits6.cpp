// 4_type_traits3 - 210 page
#include <iostream>

// ǥ��  traits �� ����Ϸ���
#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. �����Ϸ���
	bool b1 = std::is_pointer<T>::value;

	// 2. ���� Ÿ���� ��������
	typename std::remove_pointer<T>::type n1;
}

int main()
{
	int n = 0;
	foo(&n);
}
