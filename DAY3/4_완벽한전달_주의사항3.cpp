// 9_�Ϻ�������_���ǻ���3

// forwarding reference �̾߱�

template<typename T> class Test
{
public:

	void foo(T&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t;			
	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n); 
	t.foo(10); 
}