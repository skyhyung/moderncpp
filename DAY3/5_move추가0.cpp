// 2_완벽한전달8.cpp -> 5_move추가0.cpp 로 이름 변경
#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() {}
	Object(const Object& o) { std::cout << "copy" << std::endl; }
	Object(Object&& o)      { std::cout << "move" << std::endl; }
};

int main()
{
	Object o1;
	Object o2 = o1;			   // copy
	Object o3 = std::move(o1); // move
}
