// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo() // void foo(Test* this)
	{
		// 멤버 데이타 캡쳐 ?
		// auto f = [](int a) { return a + data; }; // error
		// auto f = [data](int a) { return a + data; }; // error
											// data는 지역변수 아님

		// 핵심 : 람다 표현식이 this 캡쳐를 사용하면 모든 멤버 데이타 접근가능
		// auto f = [this](int a) { return a + data; }; // a + this->data 로변경

		auto f = [this]() { data = 100; };

		f(); // data = 100 이 실행됩니다. 될까요 ? 
			 // 원본 수정일까요 ? 복사본일까요 ?
			// 멤버데이타 원본 "data"를 수정한 코드
		
	}
};

int main()
{
	Test t;
	t.foo(); 
}

