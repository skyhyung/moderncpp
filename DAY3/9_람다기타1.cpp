// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// ��� ����Ÿ ĸ�� ?
		auto f = [](int a) { return a + data; };

	}
};

int main()
{
	Test t;
	t.foo(); 
}

