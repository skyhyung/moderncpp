// 2_가변인자템플릿1-1

template<typename T> void f1(T a) {}

template<typename ... Types> void f2(Types ... args) {}

void f3(...) {}  // 함수가 한개 인데. 다양한 인자를 몇개라도 받는다.
				 // 위 코드는 함수를 생성하는 것

int main()
{
	f1(1);      // ok
	f1(3.4);	// ok
	f1(1, 3.4); // error

	f2(1);      // ok
	f2(1, 3.4); // Types : int, double
				// args  : 1, 3.4

}



