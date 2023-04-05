#include <iostream>
using namespace std;
// 160 page
template<typename T, typename U> struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

int main()
{
	// �Ʒ� ó�� ������ ����� ������.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short
}

