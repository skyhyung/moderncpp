#include <iostream>
#include <vector>

std::vector<int> v;

template<typename ... Types>
void Show(Types ... args)
{
	// 초기값  op ... op pack
	//(std::cout << ... << args);
	// ((( std::cout << E1) << E2) <<E3)

	// pack 위치에 pack 을 사용하는 패턴이 와도 됩니다.
	// pack            op  ...
	// (v.push_back(args) ,   ...);
	// ( v.push_back(E1), (v.push_back(E2) , ( v.push_back(E3) )))

	// pack 의 패턴				 op ...	
	((std::cout << args << ", ")  , ...);
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



