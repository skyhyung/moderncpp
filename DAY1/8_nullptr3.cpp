//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0); // int,   0은 int 타입 이므로
	foo(0.0); // double
	foo(false ); // bool. false 는 bool 타입의 리터럴
	foo(nullptr ); // char*  nullptr 은 포인터형 리터럴(키워드)

	// 모든 리터럴은 타입이 있습니다.
	10;		// int
	3.4;	// double
	false;	// bool
	nullptr;// std::nullptr_t 라는 타입 입니다.

	std::nullptr_t a = nullptr; 
	// 이제 nullptr 대신 a사용해도 됩니다.
	// => nullptr_t 타입의 객체는 모든 포인터로 암시적 형변환 된다
	//    라는 문법이 있습니다.

	int* p1 = a;
	char* p2 = a;
}



