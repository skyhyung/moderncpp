// 12_delete_function 37 page

int gcd(int a, int b) 
{
	// 최대 공약수 반환
	return 0;
}

// C++11 함수삭제 문법 - 사용하는 코드가 있으면 에러 발생해달라.
double gcd(double a, double b) = delete;

int main()
{
	gcd(10, 20);
	gcd(1.3, 3.4);
}
