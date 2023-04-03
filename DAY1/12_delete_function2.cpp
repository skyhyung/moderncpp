class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 컴파일러가 자동으로 제공하는 멤버 함수를 
	// 만들지 말라고 하려면 삭제 하면 됩니다.
	Point(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // 컴파일러가 만들어주는 복사생성자사용
}
