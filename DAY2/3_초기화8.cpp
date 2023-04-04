// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// 아래 코드는 
	// => 초기값 1, 2, 3, 4 ,5 는 스택에 놓이고
	// => e가 시작 주소와 갯수( 또는 시작과 마지막 다음 주소)로 관리
	// vector 사용하면 안되나요 ?  => 모든 요소가 힙에 놓이게 됩니다.
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// initializer_list는 함수인자로 사용하려고 만들었습니다.
	// foo 에는 int 타입을 몇개라도 보낼수 있습니다.
	foo({ 1,2,3 });
	foo({ 1,2,3,4,5,6 });
	
}


