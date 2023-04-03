// 9_enum - 32 page
enum DAYOFWEEK { SUN = 0, MON = 1, TUE = 2};

//void foo(int dayofaweek)     {} // bad
void foo(DAYOFWEEK dayofaweek) {} // good

int main()
{
//	foo(0);  
	foo(SUN);	// ok
//	foo(10);	// error

	int MON = 10; // ok
//	foo(MON); // error. 지역변수
	foo(SUN); // ok. 하지만 아래 코드가 더 좋다.
	foo(DAYOFWEEK::SUN); // good
}





