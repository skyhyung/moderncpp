// 1_초기화10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2);
	std::vector<int> v4{10, 2};


	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;	
	std::vector<int> v6 = {10}; 
}




