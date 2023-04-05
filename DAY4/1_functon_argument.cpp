// github.com/codenuri/moderncpp,  DAY4.zip 

#include <string>

// 인자로 전달받은 객체를 읽기만 하려고 합니다.(in parameter)
// 다음중 좋은 것은 ?
void f1(std::string s)        { } // bad
void f2(const std::string& s) { } // good

// 아래 코드는 어떨까요 ?
void f3(int n)		  { int a = n; } // good
void f4(const int& n) { int a = n; } // bad

// 핵심. in parameter 를 만들때(인자를 읽기만 하는 경우)
// primitive type   : call by value
// user define type : const &


int main()
{
	int v = 10;
	f3(v);
	f4(v);
}
