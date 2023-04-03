enum DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

//void foo(int dayofaweek)     {} // bad
void foo(DAYOFWEEK dayofaweek) {} // good

int main()
{

	int n1 = DAYOFWEEK::MON;
	DAYOFWEEK d1 = 10;

	DAYOFWEEK d2 = MON;
	DAYOFWEEK d3 = DAYOFWEEK::MON;

}





