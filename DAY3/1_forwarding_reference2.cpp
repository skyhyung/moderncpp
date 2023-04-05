// 91 page
int main()
{
	int n = 10;

	// 1. 포인터의 포인터는 만들수 있습니다. - 2중 포인터
	int *p = &n;
	int* *pp = &p;

	// 2. reference 의 reference 는 직접 코드로 만들수 없습니다.
	int& r = n;
//	int& &rr = r;	// error

	// 3. 타입 추론중에 나오는 reference 의 reference는 에러아닙니다.
	// => reference collapsing 규칙으로 해석됩니다.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n;	// int&  &		=> int&
	RREF& r4 = n;	// int&& &		=> int&
	LREF&& r5 = n;	// int&  &&		=> int&
	RREF&& r6 = 10;	// int&& &&		=> int&&

	// referenc collapsing 이 적용되는 경우
	// 1. using 또는 typedef
	// 2. template
	// 3. decltype
	// 4. auto 

	int x[3] = { 1,2,3 };

	decltype(x[0])& r = x[0];
}

template<typename T> void foo(T a)
{
	T& r = a;	// r의 타입은 ? 
				// int& & r = a;
				// int& r = a;
}

int n = 0;
foo<int&>(n);




