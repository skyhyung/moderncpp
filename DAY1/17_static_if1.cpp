/*
// 아래 코드가 왜 에러인지 생각해 보세요 ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error, int 인 data를 * 연산할수 없다.
	}
};
int main()
{
	A a;
}
*/
template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; 
	}
};
int main()
{
	A<int> a;
	a.foo(); // 사용해야만 "템플릿 => 실제class" 를 만들때
			 // 포함 됩니다.

	// 지연된 인스턴스화(C++98 문법)
	// => 클래스 템플릿의 멤버 함수중 사용된 것만
	// => 실제 인스턴스화 된다.(C++ 클래스에 포함된다는 것)
}



