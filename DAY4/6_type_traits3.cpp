#include <iostream>
#include <type_traits>

int n;		// 변수 이름 : n		 타입 : int
int x[3];	// 변수 이름 : x		 타입 : int[3]
			//							T[N]


template<typename T> struct is_array
{
	static constexpr bool value = false; 
	static constexpr int size = -1;
};

template<typename T, int N> struct is_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(T& a)
{
	// is_array 만들어 보세요
	if ( is_array<T>::value ) 
		std::cout << "배열 크기는 " << is_array<T>::size  << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}
