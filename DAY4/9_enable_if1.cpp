// 6_enable_if1.cpp

template<bool, typename T = void > struct enable_if
{
	typedef  T type;
};

template<typename T> struct enable_if<false, T> 
{
};

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1; 
	enable_if<true>::type       n2; 
	enable_if<false, int>::type n3; 
}