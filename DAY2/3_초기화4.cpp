// 58 page
class Vector
{
	int sz;
public:
	Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10); 
	Vector v2 = 10; 
	Vector v3{ 10 };
	Vector v4 = { 10 };

	//----------------
	foo(10); // ?
}







