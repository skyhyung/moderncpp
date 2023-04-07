#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
};

template<typename T> 
void copy_type(T* dst, T* src, std::size_t sz)
{
	if (std::is_trivially_copyable_v<T>)
	{
		std::cout << "memcpy 사용" << std::endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else
	{
		std::cout << "복사 생성자 사용" << std::endl;
		
		while (sz--)
		{
		//	new (dst) T;		// 디폴트 생성자
			new (dst) T(*src);	// 복사 생성자

			++dst, ++src;
		}
	}
}

int main()
{
	Point buff1[10];
	Point buff2[10];

	copy_type(buff1, buff2, 10);
}
