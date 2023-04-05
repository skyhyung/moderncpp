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
// T&    : 임의 타입의 lvalue 만 받겠다는 것

// T&&   : 임의 타입의 lvalue 와 rvalue 모두 받을수 있다.
// => "받을수 있다" 의 의미는, 받을수 있는 함수를 생성한다는것
// => 생성된 함수는 call by value 가 아닌 "call by reference!!"

// 아래 코드 외우세요.
// lvalue 전달, f4(n) : T= int&		T&&= int& &&		f4(int& a)
// rvalue 전달, f4(3) : T= int		T&&= int&&			f4(int&& a)

// modern effective c++ 책에서
// "universal reference" 라고 부르자고 제안 했지만
// "forwarding reference" 라고 부르자고 표준위원회가 결정



template<typename T> void f3(T& a)
{}
int main()
{
	int n = 3;

	// 1. 타입을 명시적으로 전달하는 경우
	f3<int>(n );	// T=int	T&=int&		f3(int& a)
	f3<int&>(n );	// T=int&   T&=int& &	f3(int& a)
	f3<int&&>(n );	// T=int&&	T&=int&& &	f3(int& a)

	// 2. 타입을 명시적으로 전달하지 않는 경우
	// => 컴파일러는 함수 인자를 보고 함수를 생성한다.!!
	f3(10); // T 를 int, int&, int&& 중 어떤것으로 결정해도
			// 10을 받을수 없다. 에러!!
	f3(n);	// T= int 로 결정됨.
}






template<typename T> void f4(T&& a)
{}

int main()
{
	int n = 3;

	// 1. 타입을 명시적으로 전달할때
	f4<int>(3 );	// T=int		T&&=int&&		f4(int&& a)
	f4<int&>(n );	// T=int&		T&&=int& &&		f4(int&  a)
	f4<int&&>(3 );	// T=int&&		T&&=int&& &&	f4(int&& a)

	// 2. 타입을 명시적으로 전달하지 않는 경우
	// => 컴파일러가 인자를 보고 타입결정
	f4(n);	// T= int&		f4(int& a )
			// n은 int 인데.. 왜 T=int& 인가요 ?
			// 에러없이 전달받는 함수를 생성하기위해서 C++진영에서 만든 규칙

	f4(3);	// T= int		f4(int&& a)
}



