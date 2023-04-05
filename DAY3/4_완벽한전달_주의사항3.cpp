// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 코드는 forwarding reference 일까요 ?
	// => 아닙니다.
	// => forwarding reference가 되려면 함수 템플릿 이어야 하는데.
	// => 아래 foo 는 함수 템플릿 아닙니다.
	// => "클래스 템플릿의 일반 멤버 함수" 입니다.
	void foo(T&& arg)
	{
	}

	// 아래 코드가 forwarding reference 입니다.
	template<typename U>
	void goo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t; // 이 순간 T 는 int로 결정
				// 멤버 함수 foo의 모양은 foo(int&&) 로 결정됨.
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);	// error
	t.foo(10);	// ok
	t.goo(n);	// ok
	t.goo(10);	// ok

}
