#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// 아래 코드중 에러를 찾아 보세요.
	std::vector<int> v1(10);  
	std::vector<int> v2 = 10; 
	goo(10); 

	std::string s1("hello"); 
	std::string s2 = "hello";

	hoo("hello");


}





