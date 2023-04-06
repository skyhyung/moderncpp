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
		// auto f = [this](int a) { return a + data; }; // 컴파일러가 a + this->data 로 변경
		// this pointer를 "복사" 한 것임. pointer를 복사해도 안의 값이 주소이기 때문에 똑같인 원본을 바라본다.
		auto f = [this]() { data = 100; }; // = this->data

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

