#include <iostream>
#include <type_traits> 
//#pragma pack(1)		// 멤버 align 을 1byte 단위로!
struct PACKET
{
	char cmd;
	int  data;
}; 

static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
				"error. unexpected padding");

template<typename T> void object_set_zero(T* p)
{
	static_assert(!std::is_polymorphic<T>::value,
				"error T has virtual function");

	memset(p, 0, sizeof(T)); 
}
class A
{
	int n;
public:
	virtual void foo() {}
};
int main()
{
	A a;
	object_set_zero(&a);
	std::cout << sizeof(PACKET) << std::endl; // ?
}


