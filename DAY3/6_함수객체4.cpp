// 3_�Լ���ü4 -  137 page ���� ���κг���

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // ȣ��
	int n2 = Add2(1, 2); // ���� �ڵ� ġȯ, 


	int(*f)(int, int) = &Add2;

	f(1, 2); 
}

