int main()
{
	int  n1 = 3.4; // C/C++ 허용. 단, 데이타 손실 발생
				   // 대부분의 다른 언어는 에러

	char c1 = 500; // ok. 하지만 오버플로우.

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };		// error
	char c2{ 500 };		// error

	int n3 = { 3.4 }; // error

	int n4{ static_cast<int>(3.4) }; // ok

}
