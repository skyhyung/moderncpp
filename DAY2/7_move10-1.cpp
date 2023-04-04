#include <iostream>
#include <vector>
#include <type_traits>

void f1() noexcept		 {} // 예외가 없다.
void f2() noexcept(true) {} // 예외가 없다.
void f3() noexcept(false) {} // 예외가 있다


class A {}; // 다른 사람이 만든 클래스

template<typename T>
class Object
{
//	int data;
//	A data;
	T data;
	std::string name;

public:
	Object() {}
	Object(const Object& other) : data(other.data), name(other.name)
	{
	}

	Object(Object&&) 
		noexcept (  std::is_nothrow_move_constructible<T>::value    )
		: data(std::move(other.data)), name(std::move(other.name))
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = std::move_if_noexcept(o1);
	


	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;

	std::pair<int, int> p1;
}

