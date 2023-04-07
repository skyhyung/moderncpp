#include <iostream>

void safe_printf() {}

void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                safe_printf(s + 1, args...); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
	// 아래 코드의 문제점을 생각해보세요
//	printf("%d, %d\n", 10);			// 인자 부족
//	printf("%d, %d\n", 10, 20, 30);	// 인자 초과

    safe_printf("% %", 10);			// 인자 부족
    safe_printf("% %", 10, 20, 30);	// 인자 초과

}
// 구글 "C++ variadic template printf" 검색후
// 1번째 링크
