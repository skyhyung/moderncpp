#include <iostream>
#include <vector>

template<typename T> class take_view
{
	T& range;
	std::size_t sz;
public:
	take_view(T& r, std::size_t sz) : range(r), sz(sz) {}
	auto begin() { return range.begin(); }
	auto end() { return range.begin() + sz; }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
//	take_view< std::vector<int> > tv(v, 3);
//	take_view tv(v, 3); // C++17 부터 템플릿 인자 생략가능합니다.

//	for (auto& n : v)
//	for (auto& n : tv)
//	for (auto& n : take_view(v, 3) )
	for (auto& n : reverse_view(v))
	{
		std::cout << n << std::endl;
	}
}















