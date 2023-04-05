#include <string>

// 인자로 전달받은 객체를 읽기만 하려고 합니다.(in parameter)
// 다음중 좋은 것은 ?
void f1(std::string s)        { }
void f2(const std::string& s) { }


void f3(int n)		  { int a = n; }
void f4(const int& n) { int a = n; }

int main()
{

}