#include <list>

// STL 의 list에 함수 몇개를 추가하려고 한다.
class MyList : public std::list<int>
{
public:
	using std::list<int>::list;

	void dump() {}
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




