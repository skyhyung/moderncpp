#include <list>

class MyList : public std::list<int>
{
public:
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);
}




