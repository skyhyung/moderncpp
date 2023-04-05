// 1_forwarding_reference3-1

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// rvalue 에 대한 reference 를 만든 다는 것
	// "temporary  maturization"
	Point&& r1 = Point(1, 2); // 임시객체에 이름을 부여해서
								// 수명을 늘리는 작업
//	Point pt2 = Point(1, 2);
	int&& r2 = 10;	// literal 로만 존재하던 값을 위한 메모리를
					// 할당해서 이름을 부여 한것
//	int r2 = 10;
}
