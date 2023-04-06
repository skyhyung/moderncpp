class Object
{
public:
	void f1(int code) {}
	static void f2(int code) {}
};
void foo(int n) {}

int main()
{
	void(*f1)(int) = &foo;
	void(*f2)(int) = &Object::f1; // ?
	void(*f3)(int) = &Object::f2; // ?
}