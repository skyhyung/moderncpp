#include <string>

// ���ڷ� ���޹��� ��ü�� �б⸸ �Ϸ��� �մϴ�.(in parameter)
// ������ ���� ���� ?
void f1(std::string s)        { }
void f2(const std::string& s) { }


void f3(int n)		  { int a = n; }
void f4(const int& n) { int a = n; }

int main()
{

}