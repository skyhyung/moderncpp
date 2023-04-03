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
	// 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10); 
	Vector v2 = 10; 
	Vector v3{ 10 };
	Vector v4 = { 10 };

	//----------------
	foo(10); // ?
}







