#include <iostream>
#include <type_traits>

// type traits : 템플릿인자 T에 대한 다양한 특성을 조사할수있는기술

template<typename T> struct is_pointer
{
//	bool value = false;		// 이렇게 하면 상수가 아닌 변수
//	enum { value = false };	// C++11 이전에 구조체 안에서 컴파일 시간
							// 상수를 만드는 유일한 기술
							// "enum hack" 이라고 불렸던 기술

	// C++11 부터는 아래 처럼 만들게 됩니다.
	static constexpr bool value = false; // 위 코드는 value 가 int지만
										// 이렇게 하면 bool 입니다.

};

template<typename T> struct is_pointer<T*>
{
	//enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// T : int, int*
	if ( is_pointer<T>::value  )

		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
