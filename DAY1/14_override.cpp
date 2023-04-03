// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상 함수 재정의시 실수(오타)
	// => 실수 했지만 에러는 아닙니다. 새로운 함수라고 컴파일러가 생각.
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// C++11 부터는 되도록(강력권장) 가상함수 재정의시 override 붙이세요
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}

};


int main()
{
}
