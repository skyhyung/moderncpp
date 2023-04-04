#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// 강력 권장 : move 계열의 함수를 직접 만들게 된다면
	//			  되도록 예외 가 발생하지 않게 만들고
	//			  noexcept 를 붙이는 것이 좋습니다.
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 무조건 복사
	Object o3 = std::move(o1); // 무조건 이동
	Object o4 = std::move_if_noexcept(o2); 
				// 이동생성자에 예외가 없으면 이동(rvalue 캐스팅)
				// 예외 가능성이 있으면 복사 생성자(lvalue 캐스팅)


	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

