// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       "표현식(expression) 에 부여" 되는 개념
// expression : 한개의 값으로 결정되는 코드 집합

int main()
{
	int n = 0;

	(n + 2) * 3 + 1;

	n = 10; // ok    "n" 이라는 표현식은 lvalue

	(n + n) = 10; // error. "n+n" 이라는 표현식은 rvalue

	(n = 20) = 10; // ok.  "n=20" 이라는 표현식은 lvalue

	++n = 10; // ok.  ++n 은 lvalue
	n++ = 10; // error. n++ 은 rvalue
}
// int 타입은 ++ 재정의 안되지만.. 원리 파악을 위해서
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
// 후위형
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}


