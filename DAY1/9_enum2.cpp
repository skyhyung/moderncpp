// C++11의 새로운 enum
enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

//void foo(int dayofaweek) {} // 예전 스타일
void foo(DAYOFWEEK dayofaweek) {} // 예전 스타일

int main()
{
	int n1 = MON; // error. MON 은 DAYOFWEEK 안에 있습니다
	int n2 = DAYOFWEEK::MON; // error. int 타입아님
	DAYOFWEEK n3 = MON; // error. MON 은 전역공간에 있지 않다

	DAYOFWEEK n4 = DAYOFWEEK::MON; // ok..
	 
	foo(MON); //error
	foo(0);  // error
	foo(100); // error
	foo(DAYOFWEEK::MON); // ok
}





