// github.com/codenuri/moderncpp,  DAY4.zip 

#include <string>
#include <string_view>

// 인자로 전달받은 객체를 읽기만 하려고 합니다.(in parameter)
// 다음중 좋은 것은 ?
void f1(std::string s)        { } // bad. string 객체 복사
void f2(const std::string& s) { } // good. const string 객체 참조. const가 있어야 string rvalue(임시객체) 를 받을 수 있다.
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
	std::string s = "test1";
	const std::string sc = "test2";
	
	f1(s);				// ok
	f1(sc);				// ok
	f1(std::string("test3"));	// ok
	f1("test");			// ok
	
	f2(s);				// ok
	f2(sc);				// ok
	f2(std::string("test3"));	// ok. void f2(std::string& s)라면 error.
					// const std::string& 는 임시객체(Rvalue)도 받을 수 있다.
	f2("test");			// ok void f2(std::string& s)라면 error. 위와 동일한 이유
	
	f3(s);				// ok
	f3(sc);				// ok
	f3(std::string("test3"));	// ok
	f3("test");			// ok

	f3(v);				// ok
	f4(v);				// ok
}
