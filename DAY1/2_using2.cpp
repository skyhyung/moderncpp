#include <unordered_set>

typedef std::unordered_set<int> SETI;
typedef std::unordered_set<double> SETD;

// 타입이 아니라 template 에 대한 별명을 만들수 없을까 ??
//typedef std::unordered_set SET; // error.
								// typedef 는 타입의 별명만 가능

// typedef : 타입의 별명 만 만들수 있다.
// using   : 타입의 별명 + 템플릿의 별명

template<typename T>
using SET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

	SET<int> s1;
	SET<double> s2;

}
