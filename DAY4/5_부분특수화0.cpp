// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	Test::data  * p; 
	Test::DWORD * p; 

	
}
int main()
{
	Test t;
	foo(t);
}



