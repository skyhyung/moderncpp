// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	auto a = 10;

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	auto a1 = n;  // a1 :
	auto a2 = r;  // a2 :
	auto a3 = c;  // a3 :
	auto a4 = cr; // a4 :

	auto& a5 = n;  // auto :  ?   a5 : ?
	auto& a6 = r; 
	auto& a7 = c; 
	auto& a8 = cr;
}


