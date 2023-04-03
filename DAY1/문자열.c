// 문자열.c
// => 아래 예제의 현상은 컴파일러마다 약간씩 다를수 있지만
// => g++, cl(vs컴파일러), clang 은 모두 동일
#include <stdio.h>

int main()
{
	char s1[] = "ABCD";
	char* s2 = "ABCD";

	*s1 = 'X';
	*s2 = 'X';

	printf("main continue\n");
}
