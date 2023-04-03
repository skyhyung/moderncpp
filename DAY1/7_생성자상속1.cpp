// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
// Derived 는 멤버 데이타는 추가하지 않았고 
// 멤버 함수 몇개를 추가 했다
class Derived : public Base
{
public:
	void foo() {}

	// C++98 스타일
//	Derived() {}
//	Derived(int n) : Base(n) {}

	// C++11 부터는 아래 처럼 만들면 생성자도 상속됩니다.
	// => 위 2개의 생성자와 동일한 효과 입니다.
	using Base::Base;
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}


