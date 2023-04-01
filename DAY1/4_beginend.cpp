// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	//int v[5] = { 1,2,3,4,5 };

	std::vector<int>::iterator p1 = v.begin();
	std::vector<int>::iterator p2 = v.end();
}