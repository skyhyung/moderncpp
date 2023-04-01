// C++11�� ���ο� enum
enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

//void foo(int dayofaweek) {} // ���� ��Ÿ��
void foo(DAYOFWEEK dayofaweek) {} // ���� ��Ÿ��

int main()
{
	int n1 = MON; // error. MON �� DAYOFWEEK �ȿ� �ֽ��ϴ�
	int n2 = DAYOFWEEK::MON; // error. int Ÿ�Ծƴ�
	DAYOFWEEK n3 = MON; // error. MON �� ���������� ���� �ʴ�

	DAYOFWEEK n4 = DAYOFWEEK::MON; // ok..
	 
	foo(MON); //error
	foo(0);  // error
	foo(100); // error
	foo(DAYOFWEEK::MON); // ok
}





