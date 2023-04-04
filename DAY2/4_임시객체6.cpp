#include <string>

template<typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? : b : a;
}

int main()
{
	const std::string& ret = max(std::string("A"), std::string("B"));

	// ret 사용해도 되나요 ??
	// => 안됩니다.
	// => 임시객체는 한번만 상수 참조로 가리킬수 있습니다.
	// => 2번의 수명연장은 안됩니다.
	//    cppreference.com    std::max 함수 참고

}
