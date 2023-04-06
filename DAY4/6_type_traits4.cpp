// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의     : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. 구조체 템플릿을 만들고 "using type = T" 넣으세요
template<typename T> struct remove_pointer
{
	using type = T;
};

// 2. 부분 특수화를 통해서 원하는 타입을 얻을수 있도록
//    타입을 분할 한다.(int* => int 와 * 로 분리)
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};


int main()
{
	remove_pointer<int*>::type n1;  // int n1
}



template<typename T> void foo(T a)
{
}
