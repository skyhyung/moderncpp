#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 1 = 10; // error. n+1 은 rvalue 

	// decltype(exp) : exp가 lvalue 면 결과는 lvalue 참조 타입
	//				   exp가 rvalue 면 결과는 값타입

//	if ( std::is_lvalue_reference<decltype(n + 1)>::value )
	if ( std::is_lvalue_reference_v<decltype(n + 1)>)
	{
		std::cout << "lvalue" << std::endl;
	}
	else 
		std::cout << "rvalue" << std::endl;
}
