#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) 의미.
	v.emplace_back(20);
	v.emplace_back(15);

	// 나이가 15살인 사람을 찾고 싶다. ?
	auto ret = std::find_if(v.begin(), v.end(),
		[](const People& p) { return p.age == 15; });


	// 나이가 k살인 사람을 찾고 싶다. ?
	int k = 15;
	auto ret = std::find_if(v.begin(), v.end(),
		[k](const People& p) { return p.age == k; });
}









