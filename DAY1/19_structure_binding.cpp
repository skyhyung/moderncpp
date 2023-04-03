// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// 모든 멤버를 꺼내고 싶다.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 의 structural binding
	auto [a, b, c] = p3d;	// auto a = p3d.x
							// auto b = p3d.y
							// auto c = p3d.z

	auto [a, b] = p3d; // error. 갯수가 맞아야 합니다.
//	int  [a, b] = p3d; // error. auto 만 가능

	int arr[3] = { 1,2,3 };
	auto [a1, a2, a3] = arr; // ok. 배열도 가능



	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

	//-------------------
	for (auto e : m)
	{
		// e는 pair
		std::string key   = e.first;
		std::string value = e.second;
	}

	for (auto [key, value] : m)
	{
		// key, value 사용
	}


}

