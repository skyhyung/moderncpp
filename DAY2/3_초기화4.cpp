// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자
	// => direct 만 가능하고 copy init 은 할수 없다.
	// => C++98 문법
	explicit Vector(int s) : sz(s) {}
};

// 핵심 : 함수의 인자 전달도 "copy initialization" 입니다.
void foo(Vector v) {} // Vector v = 10				  

int main()
{
	// 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);	// C++98, direct initialization
	Vector v2 = 10; // C++98, copy   initialization
		
	Vector v3{ 10 };    // C++11, direct initialization
	Vector v4 = { 10 }; // C++11, copy   initialization

	//----------------
	foo(10); // ?
}







