
// github.com/aosp-mirror    "Android Open Source Project"

// platform_system_core   repository 선택

// libutils/include/utils/type_helpers.h 에서 copy_type 찾으세요

#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;

	Point() = default;
};


template<typename T>

std::enable_if_t< std::is_trivially_copyable<T> > 

copy_type(T* dst, T* src, std::size_t sz)
{
	std::cout << "memcpy 사용" << std::endl;
	memcpy(dst, src, sizeof(T) * sz);
}

template<typename T>
std::enable_if_t< !std::is_trivially_copyable<T> >
copy_type(T* dst, T* src, std::size_t sz)
{
	std::cout << "복사 생성자 사용" << std::endl;
	while (sz--)
	{
		new (dst) T(*src);

		++dst, ++src;
	}
}

int main()
{
	Point buff1[10];
	Point buff2[10];

	copy_type(buff1, buff2, 10);
}
