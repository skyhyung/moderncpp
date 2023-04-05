// 2_완벽한전달8.cpp -> 5_move추가0.cpp 로 이름 변경
#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() {}
	Object(const Object& o)     { std::cout << "copy" << std::endl; }
	Object(Object&& o) noexcept { std::cout << "move" << std::endl; }
};

// C++ 표준의 move 를 직접 구현해 봅시다.
template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;  	  // copy
	Object o3 = move(o1); // move
}


