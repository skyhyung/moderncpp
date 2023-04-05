#include <vector>
#include <iostream>

template<typename T>
class vector
{
	T* buff;
public:
	vector(std::size_t sz, T value)
	{
		buff = new T[sz];
	}
	T& operator[](int idx) { return buff[idx]; }
};
// bool 을 위한 특수화 버전
template<>
class vector<bool>
{
	int* buff;
public:
	vector(std::size_t sz, bool value)
	{
		buff = new int[(sz / 32) + 1];
	}

	struct BitProxy
	{
		int* buff;
		int idx;
	
		BitProxy(int* p, int i) : buff(p), idx(i) {}

		operator bool()
		{
			std::cout << "v[] 표기가 왼쪽" << std::endl;

			// buff, idx 번째 비트값을 꺼내서 조사후 반환하세요
			return false;
		}

		BitProxy operator=(bool value)
		{
			std::cout << "v[]이 왼쪽" << std::endl;

			// 자신이 보관하고 있는 buff 메모리의 idx 번째 비트에 
			// value 값 넣기
			return *this;
		}
	};
	
	BitProxy operator[](int idx) { return BitProxy(buff, idx); }
};

int main()
{
	vector<bool> v2(10, 0);

	bool b = v2[0];
	v2[0] = false;

}

/*
int main()
{
	std::vector<int>  v1(10, 0);
	std::vector<bool> v2(10, 0);

	bool b = v2[0];
	v2[0] = false;




//	for (auto& e : v1)  // ok
	for (auto& e : v2)  // ??왜 ?? 에러일까요 ?
//	for (auto&& e : v2) // ok
	{
		e = 0;
	}
}
*/
