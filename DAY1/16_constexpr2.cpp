// C++11 의 constexpr 은 3개가 있습니다.
// 1. constexpr 상수
// 2. constexpr 함수
// 3. constexpr 제어문
// constexpr 함수 : 인자값을 컴파일 시간에 알고,
//				    컴파일 시간에 값이 필요한 표현식이라면
//					실행자체를 컴파일 시간에 해달라.
constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}
int main()
{
	int n = 5;

	int arr1[Factorial(5)]; 

	int arr2[Factorial(n)];  // error. 인자값을 컴파일러가 알수 없다.
						
	int s2 = Factorial(n);	// ok. 실행시간에 수행
	
	int s = Factorial(5); // 컴파일 시간 ? 실행시간 ?
						  //=> 컴파일러에 따라 다름.

	const int c1 = Factorial(5); // 컴파일러마다 다름

	constexpr int c2 = Factorial(5); // 컴파일 시간
}
