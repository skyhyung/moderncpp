#include <iostream>
#include <bitset>	// 비트단위로 관리하는 STL

class URandom
{
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
//		bs.set(3); // 3번째 비트만 1로
		bs.set();	// 모든 비트를 1로
	}
	int operator()()
	{
		if (bs.none())
		{
			if (recycle == true)
				bs.set();
			else
				return -1;
		}
		int k = -1;

		while (!bs.test(k = rand() % 10) );

		bs.reset(k);

		return k;
	}
};
//URandom urand;
URandom urand(true);


int main()
{
	for (int i = 0; i < 15; i++)
		std::cout << urand() << std::endl;
}
