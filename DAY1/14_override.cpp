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
	// ���� �Լ� �����ǽ� �Ǽ�(��Ÿ)
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};


int main()
{
}