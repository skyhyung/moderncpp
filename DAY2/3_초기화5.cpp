#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// �Ʒ� �ڵ��� ������ ã�� ������.
	std::vector<int> v1(10);  
	std::vector<int> v2 = 10; 
	goo(10); 

	std::string s1("hello"); 
	std::string s2 = "hello";

	hoo("hello");


}





