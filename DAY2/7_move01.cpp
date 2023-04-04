#include <iostream>
#include <string>
#include <vector>

// move 개념
// SSO : small string optimization
//		 작은 문자열에 힙에 할당하지 않고, 객체안에 보관
//		 문자열이 긴 경우만 힙에 할당
//		 보통16자(컴파일러 따라 다를수 있음) 기준

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1; // 깊은 복사(문자열 자체를 메모리 복사)
	std::string s4 = std::move(s2); // 자원의 이동
									// s2의 자원을 s4 로 이동

	std::cout << s1 << std::endl;  // "hello"
	std::cout << s2 << std::endl;  // ""


}

