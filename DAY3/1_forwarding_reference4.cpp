struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};


// 방법 1. call by value
// => 특징. 복사본을 만들어서 받게 된다.
// void foo(Point pt) {}

// 방법 2. const lvalue reference
// => 특징, 복사본이 없다.
// => 상수성 추가된다. 함수안에서 객체 변경 할수는 없다.
void foo(const Point& r) {}

//- C++ 98 에서는 위 2개 방법밖에 없다.
// C++11 이후
// 방법 3. 2개의 함수 제공
// => 상수성 추가되지 않고, 복사본도 없다
void foo(Point& r) {}
void foo(Point&& r) {}

// 방법 4. forwarding reference
// => 결국 방법3의 2개 함수를 자동생성하겠다는 의도!!
template<typename T>
void foo(T&& r)
{
}



int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
