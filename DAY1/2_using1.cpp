#include <unordered_set>
// 교재 11page
// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 

// C++11 using 사용해도 위와 동일
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n; // int n
	F     f; // 함수 포인터 f
}
