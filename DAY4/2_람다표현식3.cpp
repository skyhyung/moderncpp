#include <iostream>

// auto 와 람다 표현식
int main()
{
//	Point pt = Point();
			// C++98 : 복사 생성자 호출
			// C++11 : 이동 생성자 호출
			// => 대부분 컴파일러는 최적화 되어서 임시객체를 만들지 않고
			//    pt 의 디폴트 생성자만 호출하도록 합니다.
			// 
			// C++17 : 위 최적화가 문법으로 규정되었습니다.
			//			모든 컴파일러는 반드시 디폴트 생성자만 호출해야
			//			합니다. 
			//			"mandatory copy ellision" 이라는 문법



	// 람다 표현식의 결과를 auto 변수에 담아서 함수 처럼 사용 가능합니다.
	auto f = [](int a, int b) { return a + b; };
			// class xxx{ operator()(int a, int b){return a + b;}; xxx();

	int n = f(1, 2); // 1 + 2

	// 다음중 에러는 ?
	auto        f1 = [](int a, int b) { return a + b; }; // ok.. good
	auto&       f2 = [](int a, int b) { return a + b; }; // error.
	const auto& f3 = [](int a, int b) { return a + b; }; // ok.
											// 하지만 f1이 더 좋습니다.
	auto&&      f4 = [](int a, int b) { return a + b; }; // ok.
}

