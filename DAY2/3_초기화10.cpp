// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// �Ʒ� 2���� �������� ?
	std::vector<int> v3(10, 2);
	std::vector<int> v4{10, 2};


	// �Ʒ� �ڵ忡�� ������ ?
	std::vector<int> v5 = 10;	
	std::vector<int> v6 = {10}; 
}




