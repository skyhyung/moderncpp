// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0;

	// C++11 부터는 0 대신 nullptr 사용
	int* p2 = nullptr; // good.. 좋은 코드
	int n2 = nullptr; // error. 정수에 대입은 안됨
}
