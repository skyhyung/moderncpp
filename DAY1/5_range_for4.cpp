#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& range;
	std::size_t sz;
public:
	take_view(T& r, std::size_t sz) : range(r), sz(sz) {}

	auto begin() { return range.begin(); }
	auto begin() { return range.begin() + sz; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	for (auto& n : v)
	{
		std::cout << n << std::endl;
	}
}















