// 문자열.c
// => 아래 예제의 현상은 컴파일러마다 약간씩 다를수 있지만
// => g++, cl(vs컴파일러), clang 은 모두 동일
#include <stdio.h>

int main()
{
	char s1[] = "ABCD";
//	char* s2 = "ABCD"; // C 언어 : ok.   C++ : 에러

	const char* s2 = "ABCD"; // C++ 은 이렇게만 가능.
							// *s2 = 'X' 가 런타임 에러가 아닌
							// 컴파일 시간 에러!

	*s1 = 'X';	// ok. stack 이므로 R/W 가능
	*s2 = 'X';  // C언어 : runtime error. 상수메모리를 Write 시도

	printf("main continue\n");

	//------------------
	const char* s3 = "hello";
	const char* s4 = "hello";

	// 아래 2개의 주소를 생각해 봅시다.
	printf("%p\n", s3);
	printf("%p\n", s4);
}
