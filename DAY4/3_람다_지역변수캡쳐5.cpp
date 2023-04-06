// 149
int main()
{
	int v1 = 0, v2 = 0;

	auto f1 = [v1, &v2](int a) { ... }; // v1은 값, v2 는 reference
	auto f2 = [&v1, v2](int a) { ... }; // v2 refernce, v1 값

	auto f3 = [=](int a) { ... }; // 모든 지역변수 값 캡쳐
	auto f4 = [&](int a) { ... }; // 모든 지역변수 reference 캡쳐
								// => 단, 사용하지않으면 컴파일러최적화로
								//	  람다 클래스의 멤버 변수로 추가 안함

	auto f5 = [=, &v2](int a) { ... }; // v2는 reference, 나머지는 값
	auto f6 = [&,  v2](int a) { ... };
	auto f7 = [&, &v2](int a) { ... }; // error
							// 디폴트 모드와 다른 경우만 표기해야한다

	auto f8 = [x = v1, &y = v2](int a) { x, y };
			// v1을 값 캡쳐, 람다표현식안에서는 x이름 사용
	
			// v2 reference 캡쳐, y이름 사용

	std::string s = "ABCD";
	auto f9 = [s2 = std::move(s)]() {}; // move로 사용

	// 이제 s는 자원 없음
}




