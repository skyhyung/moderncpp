#include <vector>

int main()
{
	std::vector<int>  v1 = { 10, 0 };
	std::vector<bool> v2 = { 10, 0 };

	for (auto& e : v1)  // ok
	{
		e = 0;
	}
}
