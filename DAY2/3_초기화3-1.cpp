// 3_초기화3-1
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
void f1(Point pt) {} // Point pt = {1,2}
void f2(int n) {} // int n = {3}

Point f3() { return { 1,2 }; }

int main()
{
//	int n = 3;
	int n = { 3 };
	f2({ 3 });

	f1({ 1,2 });
}
