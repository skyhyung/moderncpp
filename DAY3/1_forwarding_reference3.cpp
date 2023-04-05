// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 10;
f1(n); // ok
f1(10);// error

f2(n); // error
f2(10);// ok
//--------------------------------------
// 함수인자로
// int&  : int 타입 lvalue만 받겠다는것
// int&& : int 타입 rvalue만 받겠다는것
// T&    :


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// 1. 타입을 명시적으로 전달하는 경우
	f3<int>(n );	// T=int	T&=int&		f3(int& a)
	f3<int&>(? );	// T=?    T&=?			f3(? a)
	f3<int&&>(? );	// T=?    T&=?			f3(? a)
}






template<typename T> void f4(T&& a)
{
}

