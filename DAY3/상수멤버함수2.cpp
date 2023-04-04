class Point
{
public:
	int x, y;
	void set(int a, int b) // void set(Point* this, int a, int b)
	{ 
		x = a;		// this->x = a;
		y = b;		// this->y = b;
	}
	/*
	// C++23 부터 멤버 함수 작성시 this를 직접 표기하는 문법등장
	void set2(this Point& pt, int a, int b)
	{
		pt.x = a;
		pt.y = b;
	}
	*/
};
int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(10, 20); // set(&p2, 10, 20)

	const Point p3;
	p3.set(10, 20); // set(&p3, 10, 20);
					// 인데, p3가 const 객체 이므로error
}
