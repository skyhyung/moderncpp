#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #2

class Object
{
private:
	std::string name;
public:
	// #1. ���ڰ� non-const lvalue reference �ΰ��
	void foo(std::string& s)
	{

	}

	// #2. ���ڰ� const reference �� ���
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// #3. ���� ���� ������ ���� �Լ������� ����ϴ� ���� �ƴ϶�
	//     ��� ����Ÿ� �����ϴ� ���.
	void set_name(const std::string& n) { name = n; }
};

int main()
{
	std::string s = "park";

	Object p;
	p.print_msg(s);
}








