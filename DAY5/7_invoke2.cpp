#include <iostream>
#include <functional>

class Object
{
public:
	void func1(int code) {}
	static void func2(int code) {}
};

void foo(int a, int b, int& c) { c = 100; }


template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f(std::forward<Types>(args)...);

	return std::invoke(f, std::forward<Types>(args)...);
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	Object obj;
	chronometry(&Object::func1, &obj, 10); // 멤버 함수의 성능측정

	std::cout << n << std::endl;
}

