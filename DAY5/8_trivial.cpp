#include <iostream>
#include <type_traits>

// Trivial : �ϴ����� "�ڸ��ϴ�" �� �ǹ��� �ܾ�
// Trivial Constructor : �����ڰ� �ϴ� ���� ����!

class A {};
class B 
{
public:
	virtual void foo() {}
};

int main()
{
	// B�� �����ڴ� trivial �ұ�� ?
}