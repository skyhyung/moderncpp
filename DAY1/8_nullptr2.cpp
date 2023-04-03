// 8_nullptr2
#include <iostream>

// 왜 nullptr을 만들었나 ?
void foo(int)   { std::cout << "int" << std::endl; }
void foo(void*) { std::cout << "void*" << std::endl; }

void goo(char*) { std::cout << "goo" << std::endl; }

int main()
{
	foo(0);  // int
	foo((void*)0);  // void*

	// 현재 C++진영의 NULL 은 아래처럼 만드는 경우가 많습니다.
	/*
#ifdef __cplusplus
#define NULL	0
#else 
#define NULL (void*)0
#endif
*/

	foo(NULL);

	goo(NULL);	// void* => char* 로의 암시적 변환 필요
				// C언어 : ok
				// C++언어 : error
	// 결국 NULL 은 혼란스럽습니다. nullptr 이 좋습니다.
	foo(nullptr);
	goo(nullptr);
}







