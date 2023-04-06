// 4_rvalue - 87 page
int x = 0;
int  foo() { return x; }
int& goo() { return x; }

// lvalue : 등호의 왼쪽, 오른쪽에 모두 올수 있는 표현식
//			이름(id)가 있고, 단일식을 넘어서 사용가능.
//			주소연산자로 주소를 구할수 있다.
//			참조를 반환하는 함수
// 
// rvalue : 등호의 왼쪽에 올수 없다. 오른쪽만 가능
//			이름이 없고, 값만 있다. 단일식에서만 사용가능
//			주소연산자로 주소를 구할수 없다.
//			값을 반환하는 함수
//			literal, 임시객체
int main()
{
	int v1 = 10, v2 = 10;

	v1 = 20; // ok.    v1 : lvalue
	
	10 = v1; // error. 10 : rvalue, 등호의 왼쪽에 올수없다
	
	v2 = v1;

	int* p1 = &v1; // ok
	int* p2 = &10; // error

	foo() = 10; // error
	goo() = 10; // ok

	const int c = 0;
	c = 10; // error.   c는 lvalue ? rvalue
			// 이름이 있고, 주소도 구할수 있다.
			// "immutable lvalue"

	// 모든 rvalue 는 상수이다 ??? 
	// 1.예    2. 아니오  => 아니오!!
	Point(1, 2).set(10, 20); // 멤버함수호출로 상태 변경가능.

	Point(1, 2).x = 10; // 상수라서 에러가 아니라
			   // rvalue 라서 에러 임시객체
}









