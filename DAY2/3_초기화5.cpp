#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // 되야 합니다. .. 잘 됩니다.
	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok.  
								// string(const char*) 생성자는
								// explicit 아님.	
	goo(10);	// 안되는것이 좋습니다.. 안 됩니다.
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error
								// vector(int) 생성자는 explicit 입니다
}





