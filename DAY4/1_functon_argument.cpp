// github.com/codenuri/moderncpp,  DAY4.zip 

#include <string>
#include <string_view>

// 인자로 전달받은 객체를 읽기만 하려고 합니다.(in parameter)
// 다음중 좋은 것은 ?
void f1(std::string s)        { } // bad
void f2(const std::string& s) { } // good
void f3(std::string_view s)   { } // best, C++17 부터

// 아래 코드는 어떨까요 ?
void f3(int n)		  { int a = n; } // good. 어차피 int 복사는 참조와 큰 차이가 없다.
void f4(const int& n) { int a = n; } 	// bad. 간접 참조이기에 역참조를 하기 위한 오버헤드가 발생한다.
					// godbolt 에서 확인하니 asm code 한줄 증가.

// 핵심. in parameter 를 만들때(인자를 읽기만 하는 경우)
// primitive type   : call by value
// user define type : const &


int main()
{
	int v = 10;
	f3(v);
	f4(v);
}
