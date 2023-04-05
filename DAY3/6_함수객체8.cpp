#include <functional> // 이 안에 이미 많은 함수객체
						// 있습니다.

int main()
{
	std::plus<int> p; // + 함수 객체
	std::multiplies<int> m; // *

	std::less<int> f1;

	int n1 = p(10, 20); // 10 + 20
	int n2 = m(10, 20); // 10 * 20

	bool b = f1(10, 20); // 10 < 20

	// 앞 예제에서 설명을 위해 Less를 만들었지만
	// 내일 부터는 표준에 있는 std::less 사용
}
