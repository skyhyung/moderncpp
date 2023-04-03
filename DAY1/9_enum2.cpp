//enum DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// C++11 의 새로운 enum : scoped enum 이라고 합니다.
enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

//void foo(int dayofaweek)     {} // bad
void foo(DAYOFWEEK dayofaweek) {} // good

int main()
{
	//							C/C++98		C++11
	int n1 = DAYOFWEEK::MON; // ok			error
	DAYOFWEEK d1 = 10;		 // error		error
	DAYOFWEEK d2 = MON;		// ok.			error
	DAYOFWEEK d3 = DAYOFWEEK::MON; // ok

}






