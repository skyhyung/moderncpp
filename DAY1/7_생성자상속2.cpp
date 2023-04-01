#include <list>

class MyList : public std::list<int>
{
public:
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




