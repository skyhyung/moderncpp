#include <functional>

int main()
{
	// STL 컨테이너는 동일 타입을 여러개 보관합니다.
	std::vector<int> v = { 1,2,3 };

	// 람다 표현식 한개를 저장하려면 auto 변수 사용
	auto f = [](int a, int b) { return a + b; };

	// 람다 표현식 여러개를 컨테이너에 보관하려면??
	std::vector< ? > v2(10);
}






