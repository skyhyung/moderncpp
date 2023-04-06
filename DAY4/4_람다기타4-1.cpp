// 4_람다기타4-1
int main()
{
	int v1 = 10;

	int(*f1)(int) = []  (int a) { return a + 0; };  // ok
	int(*f2)(int) = [v1](int a) { return a + v1; }; // errlr
}
