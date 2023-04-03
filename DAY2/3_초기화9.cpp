// 1_√ ±‚»≠9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	

	Point p2(1, 2);	
	Point p3({ 1,2 });
	Point p4{ 1,2 };	

	Point p5(1, 2, 3); 
	Point p6{ 1, 2, 3 }; 
	Point p7 = { 1,2,3 };
}


